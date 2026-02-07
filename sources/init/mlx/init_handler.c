/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:07:06 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/30 11:22:59 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	close_win(t_mlx_data *data)
{
	const char		*path = "./miniRT scene/valid_scene.rt";
	struct timeval	tv;
	struct timeval	tz;

	gettimeofday(&tv, &tz);
	if (tv.tv_usec % 2 && 0)
		printf("[1] %ld %s  %s\n", tv.tv_usec % 54545, MSG, path);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	// free(data->img.img_ptr);
	//free(data->img);
	free(data);
	exit(EXIT_SUCCESS);
}

static int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		close_win(data);
	return (0);
}

static int	mouse_handler(int button, int x, int y, void *param)
{
	t_mlx_data	*data;

	data = param;
	if (button == 1)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_rectangle(data);
		draw_circle(data, x, y);
	}
	return (0);
}

void	init_handler(t_mlx_data *data)
{
	mlx_hook(data->win_ptr, 17, 0, &close_win, data);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_mouse_hook(data->win_ptr, &mouse_handler, data);
}
