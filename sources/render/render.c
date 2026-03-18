/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:44:54 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/18 16:26:19 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "minirt.h"

#define NB_THREADS 24

typedef struct s_thread_data
{
	int			start_y;
	int			end_y;
	t_scene		*scene;
	t_mlx_data	*mlx;
}	t_thread_data;

/*
void	render(t_mlx_data	*mlx)
{
	int			x;
	int			y;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->img_pixel_ptr + offset) = color;
}

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
*/

void	*fill_zone(void *arg)
{
	t_rgb		colors[100];
	t_ray		ray;
	t_hit_data	hit;
	int			j;
	t_thread_data	*args;
	int				y;
	int				x;

	args = (t_thread_data *)arg;
	y = args->start_y;
	while (y < args->end_y)
	{
		x = 0;
		while (x < args->mlx->width)
		{
			memset(&hit, 0, sizeof(hit));
			j = 0;
			while (j < 100)
			{
				ray = generate_ray(&args->scene->camera, x, y);
				hit_obj(ray, args->scene, &hit);
				colors[j] = get_rgb(&hit, args->scene);
				j++;
			}
			my_mlx_pixel_put(&args->mlx->img, x, y, sum_rgb(colors, j));
			x++;
		}
		y++;
	}
	return (NULL);
}

void	render(t_scene *scene, t_mlx_data *mlx)
{
	pthread_t		threads[NB_THREADS];
	t_thread_data	args[NB_THREADS];
	int				i;
	int				rows_per_thread;

	init_camera(&scene->camera, mlx->width, mlx->height);
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	if (!create_mlx_image(mlx))
		return;
	rows_per_thread = mlx->height / NB_THREADS;
	i = 0;
	while (i < NB_THREADS)
	{
		args[i].scene = scene;
		args[i].mlx = mlx;
		args[i].start_y = i * rows_per_thread;
		if (i == NB_THREADS - 1)
			args[i].end_y = mlx->height;
		else
			args[i].end_y = (i + 1) * rows_per_thread;
		pthread_create(&threads[i], NULL, fill_zone, &args[i]);
		i++;
	}
	i = 0;
	while (i < NB_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}

/*
static void	render_debug(t_scene *scene, t_mlx_data *mlx)
{
	t_ray ray;
	t_mat4 cam_matrix;
	t_hit_data hit;

	memset(&hit, 0, sizeof(t_hit_data));
	hit.t = -1;
	memset(&ray, 0, sizeof(ray));
	cam_matrix = mat4_identity();
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	create_mlx_image(mlx);

	ray.dir = (t_vec3){1, 0, 0};
	hit = *hit_obj(ray, scene, &hit);
	printf("x+ %f\n", hit.t);
	my_mlx_pixel_put(&mlx->img, 100, 100, temp_color(&hit));
	
	ray.dir = (t_vec3){-1, 0, 0};
	hit = *hit_obj(ray, scene, &hit);
	printf("x- %f\n", hit.t);
	my_mlx_pixel_put(&mlx->img, 200, 200, temp_color(&hit));

	ray.dir = (t_vec3){0, 1, 0};
	hit = *hit_obj(ray, scene, &hit);
	printf("y+ %f\n", hit.t);
	my_mlx_pixel_put(&mlx->img, 300, 300, temp_color(&hit));
	
	ray.dir = (t_vec3){0, -1, 0};
	hit = *hit_obj(ray, scene, &hit);
	printf("y- %f\n", hit.t);
	my_mlx_pixel_put(&mlx->img, 400, 400, temp_color(&hit));

	ray.dir = (t_vec3){0, 0, 1}; 
	hit = *hit_obj(ray, scene, &hit);
	printf("z+ %f\n", hit.t);
	my_mlx_pixel_put(&mlx->img, 500, 500, temp_color(&hit));
	
	ray.dir = (t_vec3){0, 0, -1};
	hit = *hit_obj(ray, scene, &hit);
	printf("z- %f\n", hit.t);
	my_mlx_pixel_put(&mlx->img, 600, 600, temp_color(&hit));
	
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}*/

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
	// render_debug(&scn, mlx);
	mlx_loop(mlx->mlx_ptr);
}
