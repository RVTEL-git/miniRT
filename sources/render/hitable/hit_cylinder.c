/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:17:38 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/05 10:27:21 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_proj
{
	double	d_proj;
	double	oc_proj;
}t_proj;

static bool	check_height(t_ray ray, t_obj *cy, double ret)
{
	double	t_hit;
	t_vec3	hit_point;
	t_vec3	hit_to_center;
	double	proj;

	t_hit = ret;
	hit_point = vec3_add(ray.orig, vec3_scale(ray.dir, t_hit));
	hit_to_center = vec3_sub(hit_point, cy->pos);
	proj = vec3_dot(hit_to_center, cy->v);
	if (proj < 0 || proj > cy->height)
		return (false);
	return (true);
}

// Caméra
//   •───────────────────────► Rayon
//   ↑                    ↑
//   t=0               t=5.2  [Cylindre]
//                            Intersection !
double	hit_cylinder(t_obj *cy, t_ray ray)
{
	t_vec3	oc;
	t_proj	p;
	t_equ	equ;
	double	delt;
	double	t[2];

	cy->rad = (cy->diameter / 2);
	oc = vec3_sub(ray.orig, cy->pos);
	p.d_proj = vec3_dot(ray.dir, cy->v);
	p.oc_proj = vec3_dot(oc, cy->v);
	equ.a = vec3_dot(ray.dir, ray.dir) - p.d_proj * p.d_proj;
	equ.b = 2.0 * (vec3_dot(oc, ray.dir) - p.oc_proj * p.d_proj);
	equ.c = vec3_dot(oc, oc) - p.oc_proj * p.oc_proj - cy->rad * cy->rad;
	delt = equ.b * equ.b - 4 * equ.a * equ.c;
	if (delt <= 0.0)
		return (-1);
	t[0] = (-equ.b - sqrt(delt)) / (2 * equ.a);
	t[1] = (-equ.b + sqrt(delt)) / (2 * equ.a);
	if (t[0] > EPS && check_height(ray, cy, t[0]))
		return (t[0]);
	if (t[1] > EPS && check_height(ray, cy, t[1]))
		return (t[1]);
	return (-1);
}
