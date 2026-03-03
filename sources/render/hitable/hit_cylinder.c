/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:17:38 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/03 10:22:25 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_equ
{
	double	a;
	double	b;
	double	c;
}t_equ;

typedef struct s_proj
{
	double	d_proj;
	double	oc_proj;
}t_proj;

inline static bool	check_hight(t_ray *ray, t_obj cy, double ret)
{
	double	t_hit;
	t_vec3	hit_point;
	t_vec3	hit_to_center;
	double	proj;

	t_hit = ret;
	hit_point = vec3_add(ray->orig, vec3_scale(ray->dir, t_hit));
	hit_to_center = vec3_sub(hit_point, cy.pos);
	proj = vec3_dot(hit_to_center, cy.v);
	if (proj < 0 || proj > cy.height)
		return (false);
	return (true);
}

// Caméra
//   •───────────────────────► Rayon
//   ↑                    ↑
//   t=0               t=5.2  [Cylindre]
//                            Intersection !
double	hit_cylinder(t_obj cy, t_ray *ray)
{
	t_vec3	oc;
	t_proj	proj;
	t_equ	equ;
	double	delt;
	double	ret;

	cy.radius = (cy.diameter / 2);
	oc = vec3_sub(ray->orig, cy.pos);
	proj.d_proj = vec3_dot(ray->dir, cy.v);
	proj.oc_proj = vec3_dot(oc, cy.v);
	equ.a = vec3_dot(ray->dir, ray->dir) - proj.d_proj * proj.d_proj;
	equ.b = 2.0 * (vec3_dot(oc, ray->dir) - proj.oc_proj * proj.d_proj);
	equ.c = vec3_dot(oc, oc) - \
			proj.oc_proj * proj.oc_proj - cy.radius * cy.radius;
	delt = equ.b * equ.b - 4 * equ.a * equ.c;
	if (delt < 0)
		return (-1);
	ret = (-equ.b - sqrt(delt)) / (2 * equ.a);
	if (!check_hight(ray, cy, ret))
		return (-1);
	if (ret < 0.001)
		ret = (-equ.b + sqrt(delt)) / (2 * equ.a);
	if (ret < 0.001)
		return (-1);
	return (ret);
}
