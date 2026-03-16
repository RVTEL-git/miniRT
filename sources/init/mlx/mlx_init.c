/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratel <ratel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:36:55 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/16 22:10:02 by ratel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define TASKBAR_HEIGHT 69

static bool	init_window(t_global *minirt)
{
	t_mlx_data	*d;

	d = minirt->mlx;
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
	{
		ft_dprintf(2, "Error\nmlx init failed\n");
		return (false);
	}
	if (mlx_get_screen_size(d->mlx_ptr, &d->width, &d->height) != 0)
		ft_dprintf(2, "Warning\nInexpected mlx render(mlx_get_screen)\n");
	d->height -= TASKBAR_HEIGHT;
	d->width = 1500;
	d->height = 1000;
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->width, d->height, "minirt");
	if (!d->win_ptr)
	{
		mlx_destroy_display(d->mlx_ptr);
		free(d->mlx_ptr);
		d->mlx_ptr = NULL;
		ft_dprintf(2, "Error\nmlx new window failed\n");
		return (false);
	}
	d->img.img_ptr = NULL;
	init_handler(minirt);
	return (true);
}

bool	init_mlx_struct(t_global *minirt)
{
	minirt->mlx = malloc(sizeof (t_mlx_data));
	if (!minirt->mlx)
		return (false);
	if (!init_window(minirt))
	{
		free(minirt->mlx);
		return (false);
	}
	return (true);
}
