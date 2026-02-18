/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:36:55 by barmarti          #+#    #+#             */
/*   Updated: 2026/02/08 15:46:58 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	init_window(t_global *minirt)
{
	t_mlx_data	*d;

	d = minirt->mlx;
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
	{
		ft_dprintf(2, "Error\nmlx init failed\n");
		return (False);
	}
	if (mlx_get_screen_size(d->mlx_ptr, &d->width, &d->height) != 0)
		ft_dprintf(1, "Warning\nInexpected mlx render(mlx_get_screen)\n");
	d->height -= 69;
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->width, d->height, "RT_test");
	if (!d->win_ptr)
	{
		mlx_destroy_display(d->mlx_ptr);
		free(d->mlx_ptr);
		d->mlx_ptr = NULL;
		ft_dprintf(2, "Error\nmlx new window failed\n");
		return (False);
	}
	d->img.img_ptr = NULL;
	init_handler(minirt);
	return (True);
}

bool	init_mlx_struct(t_global *minirt)
{
	minirt->mlx = malloc(sizeof (t_mlx_data) * 1);
	if (!minirt->mlx)
		return (false);
	if (!init_window(minirt))
	{
		free(minirt->mlx);
		return (false);
	}
	return (true);
}
