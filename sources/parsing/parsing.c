/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:13:27 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/28 23:36:20 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/**
* @brief Check the len of the line id and then move the index
* to the next space needed by the next function
* 
* @param index location in the line parsed
* @param id id of the element of the scene
* @return int 
*/
void	move_index(char *line, int *index, char *id)
{
	int	id_len;

	id_len = 0;
	while (id[id_len])
		id_len++;
	*index = *index + id_len;
	while (line[*index] && ft_isspace(line[*index]))
		*index += 1;
}

bool	already_in_file(char *id, int *a_id, int *c_id, int *l_id)
{
	if (id[0] == 'A' && *a_id == 0)
		*a_id = 1;
	else if (id[0] == 'C' && *c_id == 0)
		*c_id = 1;
	else if (id[0] == 'L' && *l_id == 0)
		*l_id = 1;
	else if (!ft_strncmp(id, "sp", 2))
		return (false);
	else if (!ft_strncmp(id, "pl", 2))
		return (false);
	else if (!ft_strncmp(id, "cy", 2))
		return (false);
	else
	{
		ft_putendl_fd(2, "Error");
		ft_putchar_fd(2, id[0]);
		ft_putendl_fd(2, " Present multiple times");
		return (true);
	}
	return (false);
}

/**
 * @brief The .rt file is normally containing a scene that used
 * some specific object. Each object is define by an id. That id can be
 * 'A', 'C', 'L', 'sp', 'pl' or 'cy'. The function will look the char and
 * copy it if needed.
 * 
 * @param str the line contening the object information
 * @param id the buffer needed to copy the id of the object in question
 * @return true if the id is correct and if the copy functioned
 * @return false if the id is not a good one or if the copy failed
 */
static bool	is_valid_identifier(char *str, char id[3])
{
	if ((str[0] == 'A' || str[0] == 'C' || str[0] == 'L') && ft_isspace(str[1]))
	{
		if (!ft_strlcpy(id, str, 2))
			return (false);
		return (true);
	}
	else if (str[0] == 's' && str[1] == 'p' && ft_isspace(str[2]))
	{
		if (!ft_strlcpy(id, str, 3))
			return (false);
		return (true);
	}
	else if (str[0] == 'p' && str[1] == 'l' && ft_isspace(str[2]))
	{
		if (!ft_strlcpy(id, str, 3))
			return (false);
		return (true);
	}
	else if (str[0] == 'c' && str[1] == 'y' && ft_isspace(str[2]))
	{
		if (!ft_strlcpy(id, str, 3))
			return (false);
		return (true);
	}
	return (false);
}

/**
 * @brief The .rt file contains whole the information of the scene
 * The function goes throught the line and check, according to the subject,
 * by the id if the parameters seems in good order and dosen't contain wrong
 * format information (MIN/MAX INT exclued).
 * 
 * @param gnl_line the suposed line containing the information of the object
 * @return true if the line have a good format
 * @return false if some misconfigurated information
 */
bool	is_valid_line(char *gnl_line)
{
	int			index;
	char		id[3];
	static int	a_id;
	static int	c_id;
	static int	l_id;

	index = 0;
	ft_bzero(id, 3);
	while (ft_isspace(gnl_line[index]))
		index++;
	if (!is_valid_identifier(&gnl_line[index], id))
	{
		ft_putendl_fd(2, "Error\nBad identifier in scene file");
		return (false);
	}
	if (!already_in_file(id, &a_id, &c_id, &l_id))
		move_index(&gnl_line[index], &index, id);
	else
		return (false);
	if (!check_by_id(id, &gnl_line[index]))
	{
		error_by_id(id);
		return (false);
	}
	return (true);
}
