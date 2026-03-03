/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:43:30 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/03 09:59:39 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_equ
{
	double	a;
	double	b;
	double	c;
}t_equ;

//      Sphère (centre = sph.pos, rayon = 2)
//         ___
//       /     \
//      |   •   |  ← Centre
//       \ ___ /
//
// •────────────────►  Rayon (origine = ray.orig, direction = ray.dir)
//
// og = vecteur du centre de la sphère vers l'origine du rayon
// ◄───
double	hit_sphere(t_ray ray, t_obj sph)
{
	t_vec3	og;
	t_equ	e;
	double	t;
	double	ret;

	sph.radius = sph.diameter / 2;
	og = vec3_sub(ray.orig, sph.pos);
	e.a = vec3_dot(ray.dir, ray.dir);
	e.b = 2.0 * vec3_dot(og, ray.dir);
	e.c = vec3_dot(og, og) - sph.radius * sph.radius;
	ret = e.b * e.b - 4 * e.a * e.c;
	if (ret == 0)
		return (0);
	t = (-e.b - sqrt(ret)) / (2.0 * e.a);
	if (t > 0.001)
		return (t);
	t = (-e.b + sqrt(ret)) / (2.0 * e.a);
	if (t > 0.001)
		return (t);
	return (-1);
}
