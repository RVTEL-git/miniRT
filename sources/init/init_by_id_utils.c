/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_by_id_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:35:47 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/29 17:39:18 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	assign_three_value(int *first, int *second, )

void	pass_float(char *line, int *index)
{
	while (line[*index] && ft_isdigit(line[*index]))
		*index += 1;
	if (line[*index] && line[*index] == ".")
	{
		*index += 1;
		while (line[*index] && ft_isdigit(line[*index]))
			*index += 1;
	}
}

void	convert_three_float(t_coor temp, char *line)
{
	int	index;

	index = 0;
	temp.x = ft_atof(line);
	pass_float(line, &index);
	index++;
	temp.y = ft_atof(&line[index]);
	pass_float(line, &index);
	index++;
	temp.z = ft_atof(&line[index]);
}

void	convert_three_int(t_coor temp, char *line)
{
	int	index;

	index = 0;
	temp.x = ft_atoi(line);
	while (line[index] && ft_isdigit(line[index]))
		index++;
	index++;
	temp.y = ft_atoi(&line[index]);
	while (line[index] && ft_isdigit(line[index]))
		index++;
	index++;
	temp.z = ft_atoi(&line[index]);
}