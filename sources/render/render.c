/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratel <ratel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:44:54 by egiraud           #+#    #+#             */
/*   Updated: 2026/02/28 15:31:32 by ratel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_mlx_data	*mlx)
{
	int			x;
	int			y;

		y = -1;
	while (++y < mlx->height)
	{
		x = -1;
		while (++x < mlx->width)
			my_mlx_pixel_put(&mlx->img, x, y, BLUE_COLOR);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}

void	start_render(t_global *minirt)
{
	t_scene		scn;
	t_mlx_data	*mlx;

	scn = minirt->scene;
	(void)scn;
	mlx = minirt->mlx;
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	create_mlx_image(mlx);
	render(mlx);
	mlx_loop(mlx->mlx_ptr);
}
