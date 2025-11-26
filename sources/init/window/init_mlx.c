/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:36:55 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/26 01:50:04 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static int	close_win(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
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

static bool	init_window(t_mlx_data *data)
{
	int	height;
	int	width;


	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (False);
	if (mlx_get_screen_size(data->mlx_ptr, &width, &height) != 0)
		ft_dprintf(1, "Warning\nInexpected mlx render(mlx_get_screen)");
	data->width = width;
	data->height = height;
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "miniRT");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		return (False);
	}
	draw_rectangle(data);
	mlx_hook(data->win_ptr, 17, 0, &close_win, data);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	render(NULL, data);
	mlx_loop(data->mlx_ptr);
	return (True);
}

bool	init_mlx_struct(t_mlx_data *data)
{
	data = malloc(sizeof (t_mlx_data) * 1);
	if (!data)
		return (false);
	/*data->img = malloc(sizeof (t_mlx_img) * 1);
	if (!data->img)
	{
		free(data);
		return (false);
	}*/
	data->img.img_ptr = NULL;
	if (!init_window(data))
	{
	//	free(data->img);
		free(data);
		return (false);
	}
	return (true);
}
