/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:43:30 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/04 18:03:18 by barmarti         ###   ########.fr       */
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
double	hit_sphere(t_obj *sph, t_ray ray)
{
	t_vec3	og;
	t_equ	e;
	double	t[2];
	double	delt;

	sph->rad = sph->diameter / 2;
	og = vec3_sub(ray.orig, sph->pos);
	e.a = vec3_dot(ray.dir, ray.dir);
	e.b = 2.0 * vec3_dot(og, ray.dir);
	e.c = vec3_dot(og, og) - sph->rad * sph->rad;
	delt = e.b * e.b - 4 * e.a * e.c;
	if (delt <= 0.0)
		return (-1);
	t[0] = (-e.b - sqrt(delt)) / (2.0 * e.a);
	t[1] = (-e.b + sqrt(delt)) / (2.0 * e.a);
	if (t[0] > EPS)
		return (t[0]);
	if (t[1] > EPS)
		return (t[1]);
	return (-1);
}
