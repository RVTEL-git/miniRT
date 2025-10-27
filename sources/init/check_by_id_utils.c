/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_by_id_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:14:04 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/27 21:30:33 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_n_pass_float(char *line)
{
	int	index;
	int	index_to_comp;

	index = ft_isfloat(line, 0);
	if (index)
	{
		while (line[index] && ft_isspace(line[index]))
			index++;
		index_to_comp = ft_isfloat(&line[index], 0);
		if (index_to_comp)
		{
			index = index + index_to_comp;
			while (line[index] && ft_isspace(line[index]))
				index++;
			return (index);
		}
	}
	return (0);
}

static int	first_value(char *line, int charset)
{
	int	is_float;
	int	index;

	index = 0;
	is_float = ft_isfloat(line, charset);
	if (is_float)
	{
		if (line[is_float] && line[is_float] == ',')
			is_float++;
		return (is_float);
	}
	while (line[index] && ft_isdigit(line[index]))
		index++;
	if (line[index] && line[index] == ',')
		index++;
	else
		return (0);
	return (index);
}

static int	second_value(char *line, int charset)
{
	int	is_float;
	int	index;

	index = 0;
	is_float = ft_isfloat(&line[index], charset);
	if (is_float)
	{
		if (line[is_float] && line[is_float] == ',')
			is_float++;
		return (is_float);
	}
	while (line[index] && ft_isdigit(line[index]))
		index++;
	if (line[index] && line[index] == ',')
		index++;
	else
		return (0);
	return (index);
}

static int	third_value(char *line, int charset)
{
	int	is_float;
	int	index;

	index = 0;
	is_float = ft_isfloat(&line[index], charset);
	if (is_float)
	{
		if (line[is_float] && line[is_float] == ',')
			is_float++;
		return (is_float);
	}
	while (line[index] && ft_isdigit(line[index]))
		index++;
	if (is_float)
		return (is_float);
	if (!line[index] || (line[index] && ft_isspace(line[index])))
		return (index);
	return (0);
}

int	three_follow_value(char *line, int charset)
{
	int	index;
	int	index_to_comp;

	index = first_value(line, charset);
	if (index == 0)
		return (0);
	index_to_comp = second_value(&line[index], charset);
	if (index_to_comp == 0)
		return (0);
	index = index + index_to_comp;
	index_to_comp = third_value(&line[index], charset);
	if (index == 0)
		return (0);
	index = index + index_to_comp;
	while (line[index] && ft_isspace(line[index]))
		index++;
	return (index);
}
