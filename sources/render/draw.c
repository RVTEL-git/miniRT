/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:18:12 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/21 11:47:50 by barmarti         ###   ########.fr       */
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
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, COLOR_WHITE);
			y++;
		}
		x++;
	}
}
