/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:44:54 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/05 12:05:54 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

//void	render(t_mlx_data	*mlx)
//{
//	int			x;
//	int			y;
//
//	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
//	*(unsigned int *)(img->img_pixel_ptr + offset) = color;
//}

bool	create_mlx_image(t_mlx_data *mlx)
{
	t_mlx_img	new;

	new.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	if (!new.img_ptr)
		return (ft_printf("image creation failed\n"), 0);//exit bool
	new.img_pixel_ptr = mlx_get_data_addr(new.img_ptr, &new.bits_per_pixel, \
		&new.line_len, &new.endian);
	if (!new.img_pixel_ptr)
		return (ft_printf("image creation failed\n"), 0);//exit
	mlx->img = new;
	return (1);
}

void	render(t_scene *scene, t_mlx_data *mlx)
{
	int	x;
	int	y;
	t_ray ray;
	t_mat4 cam_matrix;

//	printf("mlx_ptr=%p\n", mlx->mlx_ptr);
//	printf("win_ptr=%p\n", mlx->win_ptr);
//	printf("width=%d height=%d\n", mlx->width, mlx->height);
//	printf("cc\n");

	cam_matrix = mat4_identity();
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	create_mlx_image(mlx);
	y = -1;
	while (++y < mlx->height)
	{
		x = -1;
		while (++x < mlx->width)
		{
			ray = generate_ray(scene, cam_matrix, x, y, mlx->width, mlx->height);
			//tests d'intersection et tout le bazar
			my_mlx_pixel_put(&mlx->img, x, y, BLUE_COLOR);
		}
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
	if (!create_mlx_image(mlx))
		return ; //exit clean
	render(&scn, mlx);
	mlx_loop(mlx->mlx_ptr);
}
