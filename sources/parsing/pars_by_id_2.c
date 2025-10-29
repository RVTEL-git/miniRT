/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_by_id_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:00:42 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/29 11:48:40 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/**
 * @brief parse the sphere line data by data to check if
 * everything seems to be in the right format
 * 
 * @param line the sphere line
 * @return true if everything is well configurated
 * @return false if it detected some undesire element
 */
bool	check_spher_line(char *line)
{
	int	index;
	int	index_to_comp;

	index_to_comp = three_follow_value(line, ',', true);
	if (index_to_comp == 0)
		return (false);
	index = index_to_comp;
	index_to_comp = ft_isfloat(&line[index], 0);
	if (index_to_comp == 0)
		return (false);
	index = index + index_to_comp;
	while (line[index] && ft_isspace(line[index]))
		index++;
	index_to_comp = three_follow_value(&line[index], ',', false);
	if (index_to_comp == 0)
		return (false);
	index = index + index_to_comp;
	if (line[index] != '\0')
		return (false);
	return (true);
}

/**
 * @brief parse the plane line data by data to check if
 * everything seems to be in the right format
 * 
 * @param line the plane line
 * @return true if everything is well configurated
 * @return false if it detected some undesire element
 */
bool	check_plane_line(char *line)
{
	int	index;
	int	index_to_comp;

	index_to_comp = three_follow_value(line, ',', true);
	if (index_to_comp == 0)
		return (false);
	index = index_to_comp;
	index_to_comp = three_follow_value(&line[index], ',', true);
	if (index_to_comp == 0)
		return (false);
	index = index + index_to_comp;
	index_to_comp = three_follow_value(&line[index], ',', false);
	if (index_to_comp == 0)
		return (false);
	index = index + index_to_comp;
	if (line[index] != '\0')
		return (false);
	return (true);
}

/**
 * @brief parse the cylinder line data by data to check if
 * everything seems to be in the right format
 * 
 * @param line the cylinder line
 * @return true if everything is well configurated
 * @return false if it detected some undesire element
 */
bool	check_cylin_line(char *line)
{
	int	index;
	int	index_to_comp;

	index_to_comp = three_follow_value(line, ',', true);
	if (index_to_comp == 0)
		return (false);
	index = index_to_comp;
	index_to_comp = three_follow_value(&line[index], ',', true);
	if (index_to_comp == 0)
		return (false);
	index = index + index_to_comp;
	index_to_comp = check_n_pass_float(&line[index]);
	if (index_to_comp == 0)
		return (false);
	index = index + index_to_comp;
	index_to_comp = three_follow_value(&line[index], ',', false);
	if (index_to_comp == 0)
		return (false);
	index = index + index_to_comp;
	if (line[index] != '\0')
		return (false);
	return (true);
}
