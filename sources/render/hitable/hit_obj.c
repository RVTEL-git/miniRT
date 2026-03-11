/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:22:49 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/09 19:42:33 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



t_hit_data	*hit_obj(t_ray ray, t_scene *scn, t_hit_data *hit)
{
	t_obj	*tmp;
	double	t;

	tmp = scn->object;
	memset(hit, 0, sizeof(t_hit_data));
	hit->t = -1;
	while (tmp)
	{
		t = -1.0;
		if (!ft_strcmp(tmp->id, "pl"))
			t = hit_plane(tmp, ray);
		else if (!ft_strcmp(tmp->id, "sp"))
			t = hit_sphere(tmp, ray);
		else if (!ft_strcmp(tmp->id, "cy"))
			t = hit_cylinder(tmp, ray);
		if (t > 0.0 && (hit->t < 0.0 || t < hit->t))
		{
			hit->obj = tmp;
			hit->did_hit = true;
			hit->t = t;
			ft_printf("hit\n");
		}
		tmp = tmp->next;
	}
	if (hit->obj)
	{
		hit->p = vec3_add(ray.orig, vec3_scale(ray.dir, t));
	}
	//hit->normal = get_normal(hit->p, hit->obj); a ajouter plus tard
	return (hit);
}
