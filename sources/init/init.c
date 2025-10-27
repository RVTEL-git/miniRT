/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:57:01 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/27 22:06:37 by barmarti         ###   ########.fr       */
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
static bool	check_file_format(char *rt_file)
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

static bool	check_file_data(char *rt_file)
{
	int		fd_rt;
	char	*buff_temp;

	fd_rt = open(rt_file, O_RDONLY);
	if (fd_rt < 0)
		ft_putendl_fd(2, "Error\nOpen failure");
	buff_temp = get_next_line(fd_rt);
	while (buff_temp)
	{
		if (!is_valid_line(buff_temp))
			return (false);
		free(buff_temp);
		buff_temp = get_next_line(fd_rt);
	}
	free(buff_temp);
	return (true);
}


bool	init_struct(char *rt_file)
{
	t_scene	scene;

	ft_bzero(&scene, sizeof(t_scene));
	if (!check_file_format(rt_file))
	{
		ft_putendl_fd(2, "Error\nWrong file format");
		return (false);
	}
	if (!check_file_data(rt_file))
		return (false);
	printf("all the data seems fine\n");
	return (true);
}
