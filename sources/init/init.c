/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:57:01 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/29 17:09:35 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief get the id of the element, then use it to store
 * the datas in the correct struct
 * 
 * @param valid_line the element struct that need to be used
 * @param scene the global struc where to store all the elements
 * @return true if the extraction succsed
 * @return false if 
 */
static bool	extract_data(char *valid_line, t_scene *scene, char *id)
{
	int		index;

	index = 0;
	valid_line = ft_strnstr(id, valid_line, ft_strlen(valid_line));
	while (valid_line[index] && ft_isspace(valid_line[index]))
		index++;
	init_by_id(id, valid_line, scene);
	if (errno == EOVERFLOW || errno == ERANGE)
	{
		manage_exctract_error(scene);
		return (false);
	}
	return (true);
}

/**
 * @brief Open the file and exctrat the first line to send it
 * int the checker function if it's usable, then, extract
 * 
 * @param rt_file the supposed .rt file
 * @return true if all the data are well agenced
 * @return false if one of the line is misconfigurated or if 
 * the exctraction failed
 */
static bool	extract_data(char *rt_file, t_scene *scene)
{
	int		fd_rt;
	char	id[3];
	char	*buff_temp;

	ft_bzero(id, 3);
	fd_rt = open(rt_file, O_RDONLY);
	if (fd_rt < 0)
		ft_putendl_fd(2, "Error\nOpen failure");
	buff_temp = get_next_line(fd_rt);
	while (buff_temp)
	{
		if (!is_valid(buff_temp, id) || !extract_data(buff_temp, &scene, id))
		{
			manage_gnl_error(fd_rt, buff_temp);
			return (false);
		}
		free(buff_temp);
		buff_temp = get_next_line(fd_rt);
	}
	free(buff_temp);
	close(fd_rt);
	return (true);
}

/**
 * @brief Open the file passed as argument, check the format of 
 * the fd then if the data are well configurated. Then
 * 
 * @param rt_file the supposed .rt file containing the scene
 * @return true if the data's file are in good and due form. 
 * @return false if one of the step fails (wrong ext name, 
 * the file is a directory, wrong data)
 */
bool	init_struct(char *rt_file)
{
	t_scene	scene;

	ft_bzero(&scene, sizeof(t_scene));
	if (!check_file_format(rt_file))
	{
		ft_putendl_fd(2, "Error\nWrong file format");
		return (false);
	}
	if (!extract_data(rt_file, &scene))
		return (false);
	return (true);
}
