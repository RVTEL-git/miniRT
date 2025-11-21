/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_by_id_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:35:47 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/03 15:39:42 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	assign_three_value(float *fst, float *scn, float *thr, t_coor *tmp)
{
	*fst = tmp->x;
	*scn = tmp->y;
	*thr = tmp->z;
	ft_bzero(tmp, sizeof(t_coor));
}

void	convert_three_value(t_scene *scene, char *line, bool use_float)
{
	if (use_float)
		convert_three_float(&scene->tmp, line);
	else
		convert_three_int(&scene->tmp, line);
}

void	convert_three_float(t_coor *temp, char *line)
{
	int	index;

	index = 0;
	temp->x = ft_atof(line);
	pass_float(line, &index);
	index++;
	temp->y = ft_atof(&line[index]);
	pass_float(line, &index);
	index++;
	temp->z = ft_atof(&line[index]);
}

void	convert_three_int(t_coor *temp, char *line)
{
	int	index;

	index = 0;
	temp->x = ft_atoi(line);
	while (line[index] && ft_isdigit(line[index]))
		index++;
	index++;
	temp->y = ft_atoi(&line[index]);
	while (line[index] && ft_isdigit(line[index]))
		index++;
	index++;
	temp->z = ft_atoi(&line[index]);
}
