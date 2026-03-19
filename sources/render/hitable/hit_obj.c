/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:22:49 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/19 17:02:27 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_hit(t_obj *obj, t_ray ray, double t, t_hit_data *hit)
{
	hit->obj = obj;
	hit->did_hit = true;
	hit->t = t;
	hit->ray = &ray;
}

void	final_hit_data(t_hit_data *hit, t_ray ray)
{
	hit->p = vec3_add(ray.orig, vec3_scale(ray.dir, hit->t));
	hit->normal = get_normal(hit, hit->obj);
	if (vec3_dot(hit->normal.compute, ray.dir) > 0.0)
		hit->normal.compute = vec3_scale(hit->normal.compute, -1.0);
}

void	hit_obj(t_ray ray, t_scene *scn, t_hit_data *hit)
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
			update_hit(tmp, ray, t, hit);
		tmp = tmp->next;
	}
	if (hit->obj)
		final_hit_data(hit, ray);
}
