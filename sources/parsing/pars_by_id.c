/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_by_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:51:04 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/31 16:47:16 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/**
 * @brief use the id's buffer to send the line in the dedicated function
 * 
 * @param id the buffer
 * @param line the line containig all the data (the id have been passed)
 * @return true if the id is existing and the line misconfigurated
 * @return false if the buffer contain corrupted data (normaly not possible)
 * or if the line is misconfigurated
 */
bool	check_by_id(char id[3], char *line)
{
	if (!ft_strncmp(id, "A", 1) && check_amb_line(line))
		return (true);
	if (!ft_strncmp(id, "C", 1) && check_cam_line(line))
		return (true);
	if (!ft_strncmp(id, "L", 1) && check_light_line(line))
		return (true);
	if (!ft_strncmp(id, "sp", 2) && check_spher_line(line))
		return (true);
	if (!ft_strncmp(id, "pl", 2) && check_plane_line(line))
		return (true);
	if (!ft_strncmp(id, "cy", 2) && check_cylin_line(line))
		return (true);
	return (false);
}

/**
 * @brief parse the ambiant light line data by data to check if
 * everything seems to be in the right format
 * 
 * @param line the ambiant light line
 * @return true if everything is well configurated
 * @return false if it detected some undesire element
 */
bool	check_amb_line(char *line)
{
	int	index;
	int	index_to_comp;

	index_to_comp = ft_isfloat(line, 0);
	if (index_to_comp == 0)
		return (false);
	index = index_to_comp;
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
 * @brief parse the camera line data by data to check if
 * everything seems to be in the right format
 * 
 * @param line the camera line
 * @return true if everything is well configurated
 * @return false if it detected some undesire element
 */
bool	check_cam_line(char *line)
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
	while (line[index] && ft_isdigit(line[index]))
		index++;
	while (line[index] && ft_isspace(line[index]))
		index++;
	if (line[index] != '\0')
		return (false);
	return (true);
}

/**
 * @brief parse the light line data by data to check if
 * everything seems to be in the right format
 * 
 * @param line the light line
 * @return true if everything is well configurated
 * @return false if it detected some undesire element
 */
bool	check_light_line(char *line)
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
	if (line[index] != '\0')
		return (false);
	return (true);
}
