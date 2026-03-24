/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:33:05 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/21 22:51:19 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Main render pipeline: Generate the pixel ray(s) with the help of
 * the camera, then check for all primitives objects if the ray hit the objects,
 * then get his rgb and do all the light calculations to get the final one 
 *
 * @return The final RGB of the pixel after all light compute
 */
int	get_final_rgb(t_thread_data	*args, int x, int y)
{
	t_ray			ray;
	t_hit_data		hit;
	t_rgb			colors[DEFAULT_AA];
	int				j;
	int				nb_rays;

	ft_memset(&hit, 0, sizeof(hit));
	j = 0;
	nb_rays = 1;
	if (args->scene->antialiasing == true)
		nb_rays = DEFAULT_AA;
	while (j < nb_rays)
	{
		ray = generate_ray(&args->scene->camera, (double)x, (double)y, j == 0);
		hit_obj(ray, args->scene, &hit);
		colors[j] = get_rgb(&hit, args->scene);
		j++;
	}
	return (sum_rgb(colors, j));
}

/**
 * @brief Initialize threads data struct
 */
void	init_thrd_args(int i, t_scene *scene, t_mlx_data *mlx, \
	t_thread_data *args)
{
	const int	rows_per_thread = mlx->height / NB_THRDS;

	args[i].scene = scene;
	args[i].mlx = mlx;
	args[i].start_y = i * rows_per_thread;
	if (i == NB_THRDS - 1)
		args[i].end_y = mlx->height;
	else
		args[i].end_y = (i + 1) * rows_per_thread;
}
