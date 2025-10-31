/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_by_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:45:17 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/31 18:15:12 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	init_ambl_line(char *line, t_scene *scene)
{
	int		index;
	t_rgb	*color;

	index = 0;
	color = &scene->a_light.color;
	scene->a_light.id = 'A';
	scene->a_light.amb_ratio = ft_atof(line);
	if (scene->a_light.amb_ratio > 1.0 || scene->a_light.amb_ratio < 0.0)
		errno = ERANGE;
	index = ft_isfloat(line, 0);
	while (line[index] && ft_isspace(line[index]))
		index++;
	convert_three_value(scene, &line[index], false);
	assign_three_value(&color->red, &color->green, &color->blue, &scene->tmp);
	if (color->red > 255 || color->red < 0)
		errno = ERANGE;
	if (color->green > 255 || color->green < 0)
		errno = ERANGE;
	if (color->blue > 255 || color->blue < 0)
		errno = ERANGE;
}

static void	init_cam_line(char *line, t_scene *scene)
{
	int		index;
	t_coor	*view;
	t_coor	*vec3;

	index = 0;
	view = &scene->camera.view;
	vec3 = &scene->camera.vec3;
	scene->camera.id = 'C';
	convert_three_value(scene, line, true);
	assign_three_value(&view->x, &view->y, &view->z, &scene->tmp);
	pass_three_value(line, &index, true);
	convert_three_value(scene, &line[index], true);
	assign_three_value(&vec3->x, &vec3->y, &vec3->z, &scene->tmp);
	pass_three_value(line, &index, true);
	if (vec3->x > 1 || vec3->x < -1)
		errno = ERANGE;
	if (vec3->y > 1 || vec3->y < -1)
		errno = ERANGE;
	if (vec3->z > 1 || vec3->z < -1)
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
// 	else if (!ft_strncmp(id, "sp", 2))
// 		init_spher_line(line, scene);
// 	else if (!ft_strncmp(id, "pl", 2))
// 		init_plane_line(line, scene);
// 	else if (!ft_strncmp(id, "cy", 2))
// 		init_cylin_line(line, scene);
}