/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:33:08 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/04 16:56:41 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	hit_plane(t_obj pl, t_ray ray)
{
	double	denom;
	double	t;

	denom = vec3_dot(ray.dir, pl.v);
	if (fabs(denom) > EPS)
		return (-1);
	t = vec3_dot(vec3_sub(pl.pos, ray.orig), pl.v) / denom;
	if (t > EPS)
		return (t);
	return (-1);
}
