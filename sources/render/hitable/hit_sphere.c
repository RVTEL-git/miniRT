/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:43:30 by barmarti          #+#    #+#             */
/*   Updated: 2026/02/26 15:40:03 by barmarti         ###   ########.fr       */
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
bool	hit_sphere(t_ray ray, t_obj sph)
{
	t_vec3	og;
	t_equ	eq;
	double	t;
	double	ret;

	sph.radius = sph.diameter / 2;
	og = vec3_sub(ray.orig, sph.pos);
	eq.a = vec3_dot(ray.dir, ray.dir);
	eq.b = 2.0 * vec3_dot(og, ray.dir);
	eq.c = vec3_dot(og, og) - sph.radius * sph.radius;
	ret = eq.b * eq.b - 4 * eq.a * eq.c;
	if (t > 0)
		return (t);
	return (t);
}
