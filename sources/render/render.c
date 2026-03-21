/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:44:54 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/21 22:35:19 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdatomic.h>
#include <pthread.h>
#include "minirt.h"

void	*fill_zone(void *arg)
{
	t_thread_data	*args;
	int				y;
	int				x;
	int				final_rgb;

	args = (t_thread_data *)arg;
	y = args->start_y;
	while (y < args->end_y)
	{
		x = 0;
		while (x < args->mlx->width)
		{
			final_rgb = get_final_rgb(args, x, y);
			my_mlx_pixel_put(&args->mlx->img, x, y, final_rgb);
			x++;
		}
		y++;
	}
	printf("thread: %d\n", atomic_fetch_add(args->counter, 1));
	return (NULL);
}

void	create_render_thread(t_scene *scene, t_mlx_data *mlx)
{
	int				i;
	atomic_int		cntr;
	pthread_t		threads[NB_THRDS];
	t_thread_data	args[NB_THRDS];

	i = 0;
	atomic_store(&cntr, 0);
	while (i < NB_THRDS)
	{
		init_thrd_args(i, scene, mlx, args);
		args[i].counter = &cntr;
		pthread_create(&threads[i], NULL, fill_zone, &args[i]);
		i++;
	}
	while (atomic_load(&cntr) < NB_THRDS)
		mlx_put_image_to_window(mlx->mlx_ptr, \
			mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	i = 0;
	while (i < NB_THRDS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void	render(t_scene *scene, t_mlx_data *mlx)
{
	init_camera(&scene->camera, mlx->width, mlx->height);
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	if (!create_mlx_image(mlx))
		return ;
	create_render_thread(scene, mlx);
	printf("Image rendered, press h to show commands\n");
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
		return ;
	render(&scn, mlx);
	mlx_loop(mlx->mlx_ptr);
}
