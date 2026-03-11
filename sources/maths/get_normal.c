/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:40:19 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/11 15:38:01 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_normal	init_normal(t_hit_data *hit, t_obj *obj)
{
	t_normal	ret;

	ret.dir = hit->p;
	ret.orig = obj->pos;
	return (ret);
}

t_vec3	compute_normal_plane(t_obj *plane)
{
	t_vec3	ret;

	ret = plane->v;
	ret = vec3_normalize(ret);
	return (ret);
}

t_vec3	compute_normal_sphere(t_hit_data *hit, t_obj *sphere)
{
	t_vec3	ret;

	ret = vec3_sub(hit->p, sphere->pos);
	ret = vec3_normalize(ret);
	return (ret);
}

t_vec3	compute_normal_cylinder(t_hit_data *hit, t_obj *cylinder)
{
	t_vec3	og;
	t_vec3	proj;
	t_vec3	ret;
	double	t;

	og = vec3_sub(hit->p, cylinder->pos);
	t = vec3_dot(og, cylinder->v);
	proj = vec3_scale(cylinder->v, t);
	ret = vec3_normalize(vec3_sub(og, proj));
	return (ret);
}

t_normal	get_normal(t_hit_data *hit, t_obj *obj)
{
	t_normal	ret;

	ret = init_normal(hit, obj);
	if (!ft_strcmp(obj->id, "pl"))
		ret.compute = compute_normal_plane(obj);
	else if (!ft_strcmp(obj->id, "sp"))
		ret.compute = compute_normal_sphere(hit, obj);
	else if (!ft_strcmp(obj->id, "cy"))
		ret.compute = compute_normal_cylinder(hit, obj);
	return (ret);
}
