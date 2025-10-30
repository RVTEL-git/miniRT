/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_by_id_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:13:26 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/30 15:46:48 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	pass_float(char *line, int *index)
{
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

static void	pass_three_float(char *line, int *index)
{
	pass_float(line, index);
	pass_float(line, index);
	pass_float(line, index);
}

void	pass_three_value(char *line, int *index, bool use_float)
{
	while (line[*index] && ft_isspace(line[*index]))
		*index += 1;
	if (use_float)
		pass_three_float(line, index);
	else
		pass_three_int(line, index);
	while (line[*index] && ft_isspace(line[*index]))
		*index += 1;
}
