/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:22:06 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/19 17:46:17 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	s_rgb_to_int(t_vec3 rgb)
{
	rgb.rd = pow(rgb.rd, 1.0 / 2.2);
	rgb.grn = pow(rgb.grn, 1.0 / 2.2);
	rgb.blu = pow(rgb.blu, 1.0 / 2.2);
	rgb.rd *= 255;
	rgb.grn *= 255;
	rgb.blu *= 255;
	return ((int)rgb.rd << 16 | (int)rgb.grn << 8 | (int)rgb.blu);
}

//t_rgb	ray_color(t_ray ray)
//{
//	t_did_hit	hit;
//
//	ft_bzero(&hit, sizeof(t_did_hit));
//	hit.t = -1;
//	hit = 
//}
