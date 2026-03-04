/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_by_id_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:13:26 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/03 11:21:27 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pass_double(char *line, int *index)
{
	if (line[*index] && line[*index] == '-')
		*index += 1;
	while (line[*index] && ft_isdigit(line[*index]))
		*index += 1;
	if (line[*index] && line[*index] == '.')
	{
		*index += 1;
		while (line[*index] && ft_isdigit(line[*index]))
			*index += 1;
	}
}

static void	pass_three_int(char *line, int *index)
{
	while (line[*index] && ft_isdigit(line[*index]))
		*index += 1;
	*index += 1;
	while (line[*index] && ft_isdigit(line[*index]))
		*index += 1;
	*index += 1;
	while (line[*index] && ft_isdigit(line[*index]))
		*index += 1;
	*index += 1;
}

static void	pass_three_double(char *line, int *index)
{
	pass_double(line, index);
	*index += 1;
	pass_double(line, index);
	*index += 1;
	pass_double(line, index);
}

void	pass_three_value(char *line, int *index, bool use_double)
{
	while (line[*index] && ft_isspace(line[*index]))
		*index += 1;
	if (use_double)
		pass_three_double(line, index);
	else
		pass_three_int(line, index);
	while (line[*index] && ft_isspace(line[*index]))
		*index += 1;
}
