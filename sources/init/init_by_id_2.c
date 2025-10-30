/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_by_id_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:23:35 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/30 15:30:52 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	init_object(char *line, t_scene *scn, char *id)
{
	int		index;
	t_obj	*obj;

	scn->object = malloc(sizeof(t_obj));
	index = 0;
	obj = scn->object;
	ft_strlcpy(obj->id, id, 3);
	convert_three_value(scn, line, true);
	assign_three_value(&obj->pos.x, &obj->pos.y, &obj->pos.z, &scn->tmp);
	pass_three_value(line, &index, true);
	if (ft_strncmp(id, "sp", 2))
	{
		obj->diameter = ft_atof(&line[index]);
		index = index + ft_isfloat(&line[index], 0);
	}
	else
	{
		convert_three_value(scn, line, true);
		assign_three_value(&obj->vec3.x, &obj->vec3.y, &obj->vec3.z, &scn->tmp);
		if (obj->vec3.x > 1.0 || obj->vec3.x < -1.0)
			errno = ERANGE;
		if (obj->vec3.y > 1.0 || obj->vec3.y < -1.0)
			errno = ERANGE;
		if (obj->vec3.z > 1.0 || obj->vec3.z < -1.0)
			errno = ERANGE;
		pass_three_value(line, &index, true);
	}
	if (ft_strncmp(id, "cy", 2))
	{
		obj->diameter = ft_atof(&line[index]);
		index = index + ft_isfloat(&line[index], 0);
		obj->height = ft_atof(&line[index]);
		index = index + ft_isfloat(&line[index], 0);
	}
	convert_three_value(scn, line, true);
	assign_three_value(&obj->color.red, &obj->color.green, &obj->color.blue, &scn->tmp);
	if (obj->color.red > 255 || obj->color.red < 0)
		errno = ERANGE;
	if (obj->color.green > 255 || obj->color.green < 0)
		errno = ERANGE;
	if (obj->color.blue > 255 || obj->color.blue < 0)
		errno = ERANGE;
	ft_lstadd_back_obj(&scn->object, obj);
}

// void	init_spher_line(char *line, t_scene *scene)
// {
	
// }

// void	init_plane_line(char *line, t_scene *scene)
// {
	
// }

// void	init_cylin_line(char *line, t_scene *scene)
// {
	
// }
