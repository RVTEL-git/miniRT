/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:59:31 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/27 21:43:06 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/**
 * @brief Open a the file passed as arg with the
 * __O_DIRECTORY flag of open. If after the call
 * errno flag is set to ENOTDIR (20) it means that
 * is not a directory
 * 
 * @param rt_file the string that is the suposed .rt file
 * @return true if it's a dir
 * @return false if it's not a dir and we cans use it
 */
bool	is_dir(char *rt_file)
{
	int	fd_rt;

	fd_rt = open(rt_file, __O_DIRECTORY);
	if (errno == ENOTDIR)
		return (false);
	close(fd_rt);
	return (true);
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
	int		index;
	char	id[3];

	index = 0;
	while (gnl_line[index])
	{
		ft_bzero(id, 3);
		while (ft_isspace(gnl_line[index]))
			index++;
		if (!is_valid_identifier(&gnl_line[index], id))
			return (false);
		index++;
		while (ft_isspace(gnl_line[index]))
			index++;
		if (!check_by_id(id, &gnl_line[index]))
			return (false);
	}
	return (true);
}

/**
 * @brief Check if the string is well formated to be converted later to a float
 * 
 * @param line the supposed float
 * @param charset if the string is devided by a charset we check if it's not 
 * a parasite
 * @return int the index at the end of the supposed float or zero if the sting
 *  is not formated as a float
 */
int	ft_isfloat(char *line, int charset)
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
	if (line[index] && charset && line[index] == charset)
		return (index);
	if (!line[index] || (line[index] && ft_isspace(line[index])))
		return (index);
	return (0);
}
