/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:57:01 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/05 18:11:39 by barmarti         ###   ########.fr       */
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
static bool	get_data(char *valid_line, t_scene *scene, char *id)
{
	int		index;

	index = 0;
	valid_line = ft_strnstr(id, valid_line, ft_strlen(valid_line));
	if (valid_line[index] && id[1])
		index++;
	index++;
	while (valid_line[index] && ft_isspace(valid_line[index]))
		index++;
	init_by_id(id, &valid_line[index], scene);
	if (errno == ENOMEM || errno == ERANGE)
	{
		manage_exctract_error(scene, id, true);
		return (false);
	}
	return (true);
}

/**
 * @brief check if the data exist if it does delete it
 * 
 * @param line the line to free
 * @param fd the fd to close
 */
void	free_n_close(char *line, int fd)
{
	if (line)
		free(line);
	if (fd)
		close(fd);
	line = get_next_line(fd, true);
	free(line);
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
		return (ft_dprintf(2, "Error\nOpen failure\n"), false);
	buff_temp = get_next_line(fd_rt, false);
	while (buff_temp)
	{
		if (buff_temp[0] == '\n')
		{
			free(buff_temp);
			buff_temp = get_next_line(fd_rt, false);
			continue ;
		}
		if (!is_valid(buff_temp, id) || !get_data(buff_temp, scene, id))
			return (manage_gnl_error(fd_rt, buff_temp, scene), false);
		free(buff_temp);
		buff_temp = get_next_line(fd_rt, false);
	}
	free_n_close(buff_temp, fd_rt);
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
		ft_dprintf(2, "Error\nWrong file format\n");
		return (false);
	}
	if (!extract_data(rt_file, &scene))
		return (false);
	if (!check_full(&scene))
		return (false);
	print_struct(&scene);
	return (true);
}
