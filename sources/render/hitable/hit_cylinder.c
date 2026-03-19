/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:17:38 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/19 17:45:28 by barmarti         ###   ########.fr       */
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
	proj = vec3_dot(hit_to_center, vec3_normalize(cy->v));
	if (proj < -(cy->height / 2.0) || proj > (cy->height / 2.0))
		return (false);
	return (true);
}

/*
top center + 
vec add (c.center, vec scale (c.v, c.heigt / 2))
bottom center - 
*/
double	hit_cap(t_vec3 centre, t_vec3 normal, t_ray ray, double rad)
{
	double	t;
	double	denom;
	t_vec3	hit_point;

	denom = vec3_dot(ray.dir, normal);
	if (fabs(denom) < EPS)
		return (-1.0);
	t = vec3_dot(vec3_sub(centre, ray.orig), normal) / denom;
	hit_point = vec3_add(ray.orig, vec3_scale(ray.dir, t));
	if (vec3_distance(hit_point, centre) > rad + EPS)
		return (-1.0);
	return (t);
}

double	init_caps(t_obj *cy, t_ray ray, double ret)
{
	t_vec3	cap_top;
	t_vec3	cap_bottom;
	double	t[2];

	cap_top = vec3_add(cy->pos, vec3_scale(cy->v, cy->height / 2));
	cap_bottom = vec3_sub(cy->pos, vec3_scale(cy->v, cy->height / 2));
	t[0] = hit_cap(cap_top, cy->v, ray, cy->rad);
	t[1] = hit_cap(cap_bottom, vec3_scale(cy->v, -1), ray, cy->rad);
	if (t[0] > EPS && t[1] > EPS)
		return (fmin(t[0], t[1]));
	if (t[0] > EPS)
		return (t[0]);
	else if (t[1] > EPS)
		return (t[1]);
	return (ret);
}

t_equ	compute_cy_equ(t_obj *cy, t_ray ray)
{
	t_equ	ret;
	t_vec3	oc;
	t_proj	p;

	oc = vec3_sub(ray.orig, cy->pos);
	p.d_proj = vec3_dot(ray.dir, cy->v);
	p.oc_proj = vec3_dot(oc, cy->v);
	ret.a = vec3_dot(ray.dir, ray.dir) - p.d_proj * p.d_proj;
	ret.b = 2.0 * (vec3_dot(oc, ray.dir) - p.oc_proj * p.d_proj);
	ret.c = vec3_dot(oc, oc) - p.oc_proj * p.oc_proj - cy->rad * cy->rad;
	return (ret);
}

// Caméra
//   •───────────────────────► Rayon
//   ↑                    ↑
//   t=0               t=5.2  [Cylindre]
//                            Intersection !
double	hit_cylinder(t_obj *cy, t_ray ray)
{
	t_equ	equ;
	t_equ	dsc;
	double	t[2];

	equ = compute_cy_equ(cy, ray);
	dsc.b = -1.0;
	if (fabs(equ.a) > EPS)
	{
		dsc.a = equ.b * equ.b - 4.0 * equ.a * equ.c;
		if (dsc.a >= 0.0)
		{
			t[0] = (-equ.b - sqrt(dsc.a)) / (2.0 * equ.a);
			t[1] = (-equ.b + sqrt(dsc.a)) / (2.0 * equ.a);
			if (t[0] > EPS && check_height(ray, cy, t[0]))
				dsc.b = t[0];
			else if (t[1] > EPS && check_height(ray, cy, t[1]))
				dsc.b = t[1];
		}
	}
	dsc.c = init_caps(cy, ray, dsc.b);
	if (dsc.b > EPS && dsc.c > EPS)
		return (fmin(dsc.b, dsc.c));
	if (dsc.b > EPS)
		return (dsc.b);
	return (dsc.c);
}
