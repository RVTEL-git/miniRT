/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:07:20 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/19 15:08:44 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static inline double	clamp_scalar(double val, double min, double max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

t_vec3	vec3_clamp(t_vec3 to_clamp, double min, double max)
{
	to_clamp.a = clamp_scalar(to_clamp.a, min, max);
	to_clamp.b = clamp_scalar(to_clamp.b, min, max);
	to_clamp.c = clamp_scalar(to_clamp.c, min, max);
	return (to_clamp);
}

t_rgb	get_final(t_rgb	diffuse, t_rgb specular, t_rgb ambient)
{
	t_rgb	ret;

	ret = vec3_set(0, 0, 0);
	ret = vec3_add(diffuse, specular);
	ret = vec3_add(ret, ambient);
	return (ret);
}
