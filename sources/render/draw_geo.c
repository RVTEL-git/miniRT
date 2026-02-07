/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_geo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:18:12 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/30 11:44:05 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	draw_rectangle(t_mlx_data *data)
{
	int	x;
	int	y;

	x = 200;
	while (x < 400)
	{
		y = 200;
		while (y < 400)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, WHITE_COLOR);
			y++;
		}
		x++;
	}
}

void	draw_circle(t_mlx_data *data, int pos_x, int pos_y)
{
	double		circle_x;
	double		circle_y;
	double		distance;
	double		radius_sqrd;
	double		circle_radius;

	circle_radius = 5;
	circle_x = (int)(pos_x - circle_radius);
	radius_sqrd = circle_radius * circle_radius;
	while (circle_x <= (pos_x + circle_radius))
	{
		circle_y = (int)(pos_y - circle_radius);
		while (circle_y <= (pos_y + circle_radius))
		{
			distance = pow(circle_x - pos_x, 2) + pow(circle_y - pos_y, 2);
			if (distance < radius_sqrd)
			{
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
					circle_x, circle_y, YELLOW_COLOR);
			}
			circle_y++;
		}
		circle_x++;
	}
	draw_rays(data, pos_x, pos_y, GRAY_COLOR);
}
