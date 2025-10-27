/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_by_id_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:14:04 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/27 11:50:26 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../../includes/minirt.h>

int	ft_isfloat(char *line)
{
	int	index;

	index = 0;
	while (line[index] && ft_isdigit(line[index]))
		index++;
	if (line[index] && line[index] == '.')
		index++;
	else
		return (0);
	if (line[index] && ft_isdigit(line[index]))
		index++;
	else
		return (0);
	while (line[index] && ft_isdigit(line[index]) && !ft_isspace(line[index]))
		index++;
	if (!line[index] || (line[index] && ft_isspace(line[index])))
		return (index);
	return (0);
}

int	is_first_value(char *line)
{
	int	index;

	index = 0;
	while (line[index] && ft_isdigit(line[index]))
		index++;
	if (line[index] && line[index] == ',')
		index++;
	else
		return (false);
	return (index);
}

bool	is_second_value(char *line)
{
	int	index;

	index = 0;
}

bool	is_third_value(char *line)
{
	int	index;

	index = 0;
}

bool	is_three_value(char *line)
{
	int	index;
	int	old_index;

	index = 0;
	old_index = 0;
	if (!is_first_value(line[index]))
		return (false);
	if (line[index] && ft_isdigit(line[index]))
		index++;
	else
		return (false);
	while (line[index] && ft_isdigit(line[index]))
		index++;
	if (line[index] && line[index] == ',')
		index++;
	else
		return (false);
	if (line[index] && ft_isdigit(line[index]))
		index++;
	else
		return (false);
	while (line[index] && ft_isdigit(line[index]))
		index++;
	if (!line[index] || (line[index] && ft_isspace(line[index])))
		return (true);
	return (false);
}
