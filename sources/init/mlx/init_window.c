/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:36:55 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/30 12:05:47 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	init_window(t_mlx_data *d)
{
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		return (False);
	if (mlx_get_screen_size(d->mlx_ptr, &d->width, &d->height) != 0)
		ft_dprintf(1, "Warning\nInexpected mlx render(mlx_get_screen)");
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->width, d->height, "miniRT");
	if (!d->win_ptr)
	{
		mlx_destroy_display(d->mlx_ptr);
		return (False);
	}
	draw_rectangle(d);
	init_handler(d);
	//render(NULL, d);
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
	mlx_loop(data->mlx_ptr);
	return (true);
}
