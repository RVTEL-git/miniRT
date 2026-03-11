/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:44:54 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/11 17:57:59 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
typedef struct s_render
{
	t_vec3	p_to_light;
	
}	t_render;

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
void	vec_clamp(t_vec3 *rgb)
{
	if (rgb->x > 255)
		rgb->x = 255;
	if (rgb->y > 255)
		rgb->y = 255;
	if (rgb->z > 255)
		rgb->z = 255;
	if (rgb->x < 0)
		rgb->x = 0;
	if (rgb->y < 0)
		rgb->y = 0;
	if (rgb->z < 0)
		rgb->z = 0;
}

int temp_color(t_hit_data *hit, t_scene *scene)
{
	t_render	light;
	t_vec3		a_l;
	double		dot_p;
	t_vec3		rgb;

	(void)hit;
	if (hit->did_hit == true)
	{
		light.p_to_light = vec3_normalize(vec3_sub(scene->light.point, hit->p));
		dot_p = vec3_dot(light.p_to_light, hit->normal.compute);
		if (dot_p < 0)
			rgb = vec3_set(0,0,0);
		else
		{
			rgb.x = (hit->obj->rgb.r / 255) * scene->light.bright * dot_p;
			rgb.y = (hit->obj->rgb.g / 255) * scene->light.bright * dot_p;
			rgb.z = (hit->obj->rgb.b / 255) * scene->light.bright * dot_p;
		}
		a_l = vec3_set((hit->obj->rgb.r / 255) * scene->a_light.amb_ratio, ((hit->obj->rgb.g / 255) * scene->a_light.amb_ratio), ((hit->obj->rgb.b / 255) * scene->a_light.amb_ratio));
		t_vec3 temp = vec3_add (rgb, a_l);
		vec_clamp(&temp);
		return (s_rgb_to_int(temp));

	}
	else 
		return (BLACK_COLOR);
}



void	render(t_scene *scene, t_mlx_data *mlx)
{
	int	x;
	int	y;
	t_ray ray;
	t_hit_data hit;

	memset(&hit, 0, sizeof(t_hit_data));
	memset(&ray, 0, sizeof(ray));
	//print_cam(scene->camera);
	init_camera(&scene->camera, mlx->width, mlx->height);	
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	create_mlx_image(mlx);
	y = -1;
	while (++y < mlx->height)
	{
		x = -1;
		while (++x < mlx->width)
		{
			ray = generate_ray(&scene->camera, x, y);
			hit_obj(ray, scene, &hit);
			//if (x == 0 && y == 0)
			// printf("ray dir:%f.2,%f.2,%f.2 traced\n ", ray.dir.x, ray.dir.y, ray.dir.z);
			//tests d'intersection et tout le bazar
			my_mlx_pixel_put(&mlx->img, x, y, temp_color(&hit, scene));
		}
	}
	// ft_putstr_fd(1, "image pasted");
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
