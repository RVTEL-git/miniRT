/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:44:54 by egiraud           #+#    #+#             */
/*   Updated: 2025/11/26 01:50:06 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->img_pixel_ptr + offset) = color;
}

void	create_mlx_image(t_mlx_data *mlx)
{
	t_mlx_img new;

	new.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	if (!new.img_ptr)
		printf("image creation failed\n");//exit
	new.img_pixel_ptr = mlx_get_data_addr(new.img_ptr, &new.bits_per_pixel, &new.line_len, &new.endian);
	if (!new.img_pixel_ptr)
		printf("image creation failed\n");//exit
	mlx->img = new;
}

void	render(t_scene *scene, t_mlx_data *mlx)
{
	int x;
	int y;

	(void)scene;

//	printf("mlx_ptr=%p\n", mlx->mlx_ptr);
//	printf("win_ptr=%p\n", mlx->win_ptr);
//	printf("width=%d height=%d\n", mlx->width, mlx->height);
//	printf("cc\n");


	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	create_mlx_image(mlx);
	y = -1;
	while (++y < mlx->height)
	{
		x = -1;
		while (++x < mlx->width)
			my_mlx_pixel_put(&mlx->img, x, y, COLOR_BLUE);
	}
	
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}
