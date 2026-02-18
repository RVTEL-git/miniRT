/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:07:06 by barmarti          #+#    #+#             */
/*   Updated: 2026/02/18 10:27:47 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_mlx(t_global *data, int code)
{
	t_mlx_data	*mlx;

	mlx = data->mlx;
	ft_lstclear_obj(data->scene.object);
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
	exit (code);
}

static int	handle_input(int keysym, t_global *data)
{
	if (keysym == XK_Escape)
		close_mlx(data, EXIT_SUCCESS);
	return (0);
}

void	init_handler(t_global *minirt)
{
	t_mlx_data	*data;

	data = minirt->mlx;
	mlx_hook(data->win_ptr, 17, 0, &close_mlx, minirt);
	mlx_key_hook(data->win_ptr, &handle_input, minirt);
}
