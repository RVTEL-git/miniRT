/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:18:38 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/03 09:40:50 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	create_mlx_image(t_mlx_data *mlx)
{
	t_mlx_img	new;

	new.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	if (!new.img_ptr)
	{
		ft_dprintf(2, "Error\nmlx new image failed\n");
		return (false);
	}
	new.img_pixel_ptr = mlx_get_data_addr(new.img_ptr, &new.bits_per_pixel, \
		&new.line_len, &new.endian);
	if (!new.img_pixel_ptr)
	{
		ft_dprintf(2, "Error\nmlx data address failed\n");
		return (false);
	}
	mlx->img = new;
	return (true);
}

void	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	int	offset;

	if (x < 0 || y < 0)
		return ;
	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->img_pixel_ptr + offset) = color;
}
