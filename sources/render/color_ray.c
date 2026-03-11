/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:22:06 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/11 17:29:33 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	s_rgb_to_int(t_vec3 rgb)
{
	rgb.x *= 255;
	rgb.y *= 255;
	rgb.z *= 255;
	return ((int)rgb.x << 16 | (int)rgb.y << 8 | (int)rgb.z);
}

//t_rgb	ray_color(t_ray ray)
//{
//	t_did_hit	hit;
//
//	ft_bzero(&hit, sizeof(t_did_hit));
//	hit.t = -1;
//	hit = 
//}
