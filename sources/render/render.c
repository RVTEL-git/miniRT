/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:44:54 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/09 11:57:45 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

//void	render(t_mlx_data	*mlx)
//{
//	int			x;
//	int			y;
//
//	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
//	*(unsigned int *)(img->img_pixel_ptr + offset) = color;
//}

//bool	create_mlx_image(t_mlx_data *mlx)
//{
//	t_mlx_img	new;
//
//	new.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
//	if (!new.img_ptr)
//		return (ft_printf("image creation failed\n"), 0);//exit bool
//	new.img_pixel_ptr = mlx_get_data_addr(new.img_ptr, &new.bits_per_pixel, \
//		&new.line_len, &new.endian);
//	if (!new.img_pixel_ptr)
//		return (ft_printf("image creation failed\n"), 0);//exit
//	mlx->img = new;
//	return (1);
//}

int temp_color(t_hit_data *hit)
{
	int r;
	int g;
	int b;

	if (hit->did_hit == true)
	{
	r = (int)hit->obj->rgb.r;
	g = (int)hit->obj->rgb.g;
	b = (int)hit->obj->rgb.b;
		return (s_rgb_to_int(r, g, b));
	}
	else 
		return (0 << 16 | 0 << 8 | 0);
}

void	render(t_scene *scene, t_mlx_data *mlx)
{
	int	x;
	int	y;
	t_ray ray;
	t_mat4 cam_matrix;
	t_hit_data hit;

	memset(&hit, 0, sizeof(t_hit_data));
	memset(&ray, 0, sizeof(ray));
	print_cam(scene->camera);
	cam_matrix = mat4_identity();
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	create_mlx_image(mlx);
	y = -1;
	while (++y < mlx->height)
	{
		x = -1;
		while (++x < mlx->width)
		{
			ray = generate_ray(scene, cam_matrix, x, y, mlx->width, mlx->height);
			hit = *hit_obj(ray, scene, &hit);
			//if (x == 0 && y == 0)
			//printf("ray dir:%d,%d,%d traced\n ", (int)ray.dir.x, (int)ray.dir.y, (int)ray.dir.z);
			//tests d'intersection et tout le bazar
			my_mlx_pixel_put(&mlx->img, x, y, temp_color(&hit));
			//my_mlx_pixel_put(&mlx->img, x, y, BLUE_COLOR);
		}
	}
	ft_putstr_fd(1, "image pasted");
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}


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
	
	ray.dir = (t_vec3){-1, 0, 0};
	hit = *hit_obj(ray, scene, &hit);
	printf("x- %f\n", hit.t);

	ray.dir = (t_vec3){0, 1, 0};
	hit = *hit_obj(ray, scene, &hit);
	printf("y+ %f\n", hit.t);
	
	ray.dir = (t_vec3){0, -1, 0};
	hit = *hit_obj(ray, scene, &hit);
	printf("y- %f\n", hit.t);

	ray.dir = (t_vec3){0, 0, 1}; 
	hit = *hit_obj(ray, scene, &hit);
	printf("z+ %f\n", hit.t);
	
	ray.dir = (t_vec3){0, 0, -1};
	hit = *hit_obj(ray, scene, &hit);
	printf("z- %f\n", hit.t);
	
	my_mlx_pixel_put(&mlx->img, 400, 400, temp_color(&hit));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
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
		return ; //exit clean
	//render(&scn, mlx);
	render_debug(&scn, mlx);
	mlx_loop(mlx->mlx_ptr);
}
