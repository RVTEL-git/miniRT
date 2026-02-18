/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:43:30 by barmarti          #+#    #+#             */
/*   Updated: 2026/02/18 16:32:33 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	double	a;
	double	b;
	double	c;
	double	ret;

	sph.radius = sph.diameter / 2;
	og = vec3_sub(ray.orig, sph.pos);
	a = vec3_dot(ray.dir, ray.dir);
	b = 2.0 * vec3_dot(og, ray.dir);
	c = vec3_dot(og, og) - sph.radius * sph.radius;
	ret = b * b - 4 * a * c;
	if (ret > 0)
		return (true);
	return (false);
}
