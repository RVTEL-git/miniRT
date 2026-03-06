/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_by_id_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:14:04 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/03 11:21:27 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_n_pass_double(char *line)
{
	int	index;
	int	index_to_comp;

	index = ft_isdouble(line, 0);
	while (line[index] && ft_isspace(line[index]))
		index++;
	if (index)
	{
		index_to_comp = ft_isdouble(&line[index], 0);
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

static int	non_last_value(char *line, int charset, bool include_double)
{
	int	is_double;
	int	index;

	index = 0;
	if (include_double == true)
	{
		is_double = ft_isdouble(line, charset);
		if (is_double)
		{
			if (line[is_double] && line[is_double] == ',')
				is_double++;
			return (is_double);
		}
	}
	if (line[index] && line[index] == '-')
		index++;
	if (line[index] && !ft_isdigit(line[index]))
		return (0);
	while (line[index] && ft_isdigit(line[index]))
		index++;
	if (line[index] && line[index] == ',')
		index++;
	else
		return (0);
	return (index);
}

static int	third_value(char *line, int charset, bool include_double)
{
	int	is_double;
	int	index;

	is_double = 0;
	index = 0;
	if (include_double == true)
	{
		is_double = ft_isdouble(line, charset);
		if (is_double)
		{
			if (line[is_double] && line[is_double] == ',')
				is_double++;
			return (is_double);
		}
	}
	if (line[index] && line[index] == '-')
		index++;
	if (line[index] && !ft_isdigit(line[index]))
		return (0);
	while (line[index] && ft_isdigit(line[index]))
		index++;
	if (!line[index] || (line[index] && ft_isspace(line[index])))
		return (index);
	return (0);
}

int	three_follow_value(char *line, int charset, bool include_double)
{
	int	index;
	int	index_to_comp;

	index = 0;
	while (line[index] && ft_isspace(line[index]))
		index++;
	index = non_last_value(&line[index], charset, include_double);
	if (index == 0)
		return (0);
	index_to_comp = non_last_value(&line[index], charset, include_double);
	if (index_to_comp == 0)
		return (0);
	index = index + index_to_comp;
	index_to_comp = third_value(&line[index], charset, include_double);
	if (index_to_comp == 0)
		return (0);
	index = index + index_to_comp;
	while (line[index] && ft_isspace(line[index]))
		index++;
	return (index);
}
