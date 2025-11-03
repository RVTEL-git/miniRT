/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_by_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:45:17 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/03 14:56:40 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	init_ambl_line(char *line, t_scene *scene)
{
	int		index;
	t_rgb	*rgb;

	index = 0;
	rgb = &scene->a_light.rgb;
	scene->a_light.id = 'A';
	scene->a_light.amb_ratio = ft_atof(line);
	if (scene->a_light.amb_ratio > 1.0 || scene->a_light.amb_ratio < 0.0)
		errno = ERANGE;
	index = ft_isfloat(line, 0);
	while (line[index] && ft_isspace(line[index]))
		index++;
	convert_three_value(scene, &line[index], false);
	assign_three_value(&rgb->r, &rgb->g, &rgb->b, &scene->tmp);
	if (rgb->r > 255 || rgb->r < 0)
		errno = ERANGE;
	if (rgb->g > 255 || rgb->g < 0)
		errno = ERANGE;
	if (rgb->b > 255 || rgb->b < 0)
		errno = ERANGE;
}

static void	init_cam_line(char *line, t_scene *scene)
{
	int		index;
	t_coor	*view;
	t_coor	*v;

	index = 0;
	view = &scene->camera.view;
	v = &scene->camera.v;
	scene->camera.id = 'C';
	convert_three_value(scene, line, true);
	assign_three_value(&view->x, &view->y, &view->z, &scene->tmp);
	pass_three_value(line, &index, true);
	convert_three_value(scene, &line[index], true);
	assign_three_value(&v->x, &v->y, &v->z, &scene->tmp);
	pass_three_value(line, &index, true);
	if (v->x > 1 || v->x < -1)
		errno = ERANGE;
	if (v->y > 1 || v->y < -1)
		errno = ERANGE;
	if (v->z > 1 || v->z < -1)
		errno = ERANGE;
	scene->camera.fov = ft_atoi(&line[index]);
	if (scene->camera.fov > 180 || scene->camera.fov < 0)
		errno = ERANGE;
}

static void	init_light_line(char *line, t_scene *scene)
{
	int		index;
	t_coor	*point;

	index = 0;
	point = &scene->light.point;
	scene->light.id = 'L';
	convert_three_value(scene, line, true);
	assign_three_value(&point->x, &point->y, &point->z, &scene->tmp);
	pass_three_value(line, &index, true);
	scene->light.bright = ft_atof(&line[index]);
	if (scene->light.bright > 1.0 || scene->light.bright < 0.0)
		errno = ERANGE;
}

void	init_by_id(char *id, char *line, t_scene *scene)
{
	if (id[0] == 'A')
		init_ambl_line(line, scene);
	else if (id[0] == 'C')
		init_cam_line(line, scene);
	else if (id[0] == 'L')
		init_light_line(line, scene);
	else
		init_object(line, scene, id);
}
