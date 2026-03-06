/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:22:49 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/06 17:41:26 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_did_hit
{
	bool	did_hit;
	double	t;
	t_obj	*obj;
	t_vec3	p;
	t_vec3	normal;
}t_did_hit;

double	hit_obj(t_ray ray, t_scene *scn, t_did_hit *hit)
{
	t_obj	*tmp;
	double	t;

	tmp = scn->object;
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
			hit->t = t;
			hit->did_hit = true;
		}
		tmp = tmp->next;
	}
	hit->p = vec3_add(ray.orig, vec3_scale(ray.dir, t));
	hit->normal = get_normal(hit->p, hit->obj);
	return (hit->t);
}
