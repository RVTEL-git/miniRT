/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_by_id_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:35:47 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/03 11:21:27 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



void	assign_three_value(double *fst, double *scn, double *thr, t_coor *tmp)
{
	*fst = tmp->x;
	*scn = tmp->y;
	*thr = tmp->z;
	ft_bzero(tmp, sizeof(t_coor));
}

void	convert_three_value(t_scene *scene, char *line, bool use_double)
{
	if (use_double)
		convert_three_double(&scene->tmp, line);
	else
		convert_three_int(&scene->tmp, line);
}

void	convert_three_double(t_coor *temp, char *line)
{
	int	index;

	index = 0;
	temp->x = ft_atof(line);
	pass_double(line, &index);
	index++;
	temp->y = ft_atof(&line[index]);
	pass_double(line, &index);
	index++;
	temp->z = ft_atof(&line[index]);
}

void	convert_three_int(t_coor *temp, char *line)
{
	int	index;

	index = 0;
	temp->x = ft_atoi(line);
	if (line[index] && line[index] == '-')
		index++;
	while (line[index] && ft_isdigit(line[index]))
		index++;
	index++;
	temp->y = ft_atoi(&line[index]);
	while (line[index] && ft_isdigit(line[index]))
		index++;
	index++;
	temp->z = ft_atoi(&line[index]);
}
