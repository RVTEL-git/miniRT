/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:33:08 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/12 13:47:35 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	hit_plane(t_obj *pl, t_ray ray)
{
	// static int	time;
	double	denom;
	double	t;

	denom = vec3_dot(ray.dir, pl->v);
	//printf("denom[%d] = %f\n",time, denom);
	// time++;
	if (fabs(denom) < EPS)
		return (-1);
	t = vec3_dot(vec3_sub(pl->pos, ray.orig), pl->v) / denom;
	if (t > EPS)
		return (t);
	return (-1);
}
