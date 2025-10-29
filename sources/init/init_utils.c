/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:59:31 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/29 14:16:06 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/**
 * @brief Function used to check is the file passed as
 * argument is a .rt file.
 * We use the lenght of the string passed as argument
 * then if it's shorter than 3 it means that there's
 * not even enough char to make the '.rt' ext
 * then if it has more than 3 char we compare the 3 last
 * char with '.rt' if it passed we finaly
 * check if it's not a directory
 * 
 * @param rt_file the string that is the suposed .rt file
 * @return true if it's a termined .rt string and not a dir
 * @return false if one of the test bellow fails
 */
bool	check_file_format(char *rt_file)
{
	size_t	len;

	len = ft_strlen(rt_file);
	if (len < 3)
		return (false);
	if (ft_strncmp(&rt_file[len - 3], ".rt", 3) != 0)
		return (false);
	if (is_dir(rt_file) == true)
		return (false);
	return (true);
}

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
