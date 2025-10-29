/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_by_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:45:17 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/29 17:37:12 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	init_by_id(char *id, char *line, t_scene *scene)
{
	int	index;

	index = 0;
	while (ft_isspace(line[index]))
		index++;
	move_index(line[index], &index, id);
	if (id[0] == 'A')
		init_ambl_line(id, line, scene);
	else if (id[0] == 'C')
		init_cam_line(line, scene);
	else if (id[0] == 'L')
		init_light_line(line, scene);
	else if (!ft_strncmp(id, "sp", 2))
		init_spher_line(line, scene);
	else if (!ft_strncmp(id, "pl", 2))
		init_plane_line(line, scene);
	else if (!ft_strncmp(id, "cy", 2))
		init_cylin_line(line, scene);
}

void	convert_three_value(t_scene *scene, char *line, bool use_float)
{
	if (use_float)
		convert_three_float(scene->temp, line);
	else
		convert_three_int(scene->temp, line);
}

void	init_ambl_line(char *id, char *line, t_scene *scene)
{
	int		index;
	t_rgb	color;

	index = 0;
	color = scene->a_light.color;
	scene->a_light.id = id[0];
	scene->a_light.amb_ratio = ft_atof(line);
	if (scene->a_light.amb_ratio > 1.0 || scene->a_light.amb_ratio < 0.0)
		errno = ERANGE;
	index = ft_isfloat(line, 0);
	while (line[index] && ft_isspace(line[index]))
		index++;
	convert_three_value(scene, &line[index], false);
	color.red = scene->temp.x;
	if (color.red > 255 || color.red < 0)
		errno = ERANGE;
	color.green = scene->temp.y;
	if (color.green > 255 || color.green < 0)
		errno = ERANGE;
	color.blue = scene->temp.z;
	if (color.blue > 255 || color.blue < 0)
		errno = ERANGE;
}

void	init_cam_line(char *line, t_scene *scene)
{
	int	index;

	index = 0;
	
}

void	init_light_line(char *line, t_scene *scene)
{
	
}
