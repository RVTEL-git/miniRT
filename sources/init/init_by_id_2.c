/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_by_id_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:23:35 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/05 18:20:54 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void inline	ft_check_limits(float x, float y, float z, float lim[2])
{
	if (x > lim[0] || x < lim[1])
		errno = ERANGE;
	if (y > lim[0] || y < lim[1])
		errno = ERANGE;
	if (z > lim[0] || z < lim[1])
		errno = ERANGE;
}

static void	init_cy_obj(t_obj *obj, char *line, int *index)
{
	obj->diameter = ft_atof(&line[*index]);
	*index = *index + ft_isfloat(&line[*index], 0);
	while (&line[*index] && ft_isspace(line[*index]))
		*index += 1;
	obj->height = ft_atof(&line[*index]);
	*index = *index + ft_isfloat(&line[*index], 0);
	while (&line[*index] && ft_isspace(line[*index]))
		*index += 1;
}

static void	init_sp_obj(t_obj *obj, char *line, int *index)
{
	while (&line[*index] && ft_isspace(line[*index]))
		*index += 1;
	obj->diameter = ft_atof(&line[*index]);
	*index = *index + ft_isfloat(&line[*index], 0);
	while (&line[*index] && ft_isspace(line[*index]))
		*index += 1;
}

static void	convert_n_pass(char *line, t_scene *scn, int *index)
{
	convert_three_value(scn, &line[*index], true);
	pass_three_value(line, index, true);
}

void	init_object(char *line, t_scene *scn, char *id)
{
	int		index;
	t_obj	*ob;

	ob = ft_calloc(1, sizeof(t_obj));
	if (!ob)
		return ;
	index = 0;
	ob->id = ft_strndup(id, ft_strlen(id));
	convert_n_pass(line, scn, &index);
	assign_three_value(&ob->pos.x, &ob->pos.y, &ob->pos.z, &scn->tmp);
	if (!ft_strncmp(id, "sp", 2))
		init_sp_obj(ob, line, &index);
	else
	{
		convert_n_pass(line, scn, &index);
		assign_three_value(&ob->v.x, &ob->v.y, &ob->v.z, &scn->tmp);
		ft_check_limits(ob->v.x, ob->v.y, ob->v.z, (float [2]){1.0, -1.0});
	}
	if (!ft_strncmp(id, "cy", 2))
		init_cy_obj(ob, line, &index);
	convert_three_value(scn, &line[index], true);
	assign_three_value(&ob->rgb.r, &ob->rgb.g, &ob->rgb.b, &scn->tmp);
	ft_check_limits(ob->rgb.r, ob->rgb.g, ob->rgb.b, (float [2]){255, 0});
	ft_lstadd_back_obj(&scn->object, ob);
}
