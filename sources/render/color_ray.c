/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:22:06 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/13 15:43:33 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	s_rgb_to_int(t_vec3 rgb)
{
	rgb.red *= 255;
	rgb.green *= 255;
	rgb.blue *= 255;
	return ((int)rgb.red << 16 | (int)rgb.green << 8 | (int)rgb.blue);
}

//t_rgb	ray_color(t_ray ray)
//{
//	t_did_hit	hit;
//
//	ft_bzero(&hit, sizeof(t_did_hit));
//	hit.t = -1;
//	hit = 
//}
