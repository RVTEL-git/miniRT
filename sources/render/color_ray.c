/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:22:06 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/06 17:35:53 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	s_rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

//t_rgb	ray_color(t_ray ray)
//{
//	t_did_hit	hit;
//
//	ft_bzero(&hit, sizeof(t_did_hit));
//	hit.t = -1;
//	hit = 
//}
