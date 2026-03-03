/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:44:54 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/03 09:22:19 by barmarti         ###   ########.fr       */
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
	mlx = minirt->mlx;
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	if (create_mlx_image(mlx))
		return ;
	render(mlx);
	mlx_loop(mlx->mlx_ptr);
}
