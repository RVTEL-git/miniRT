/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:24:40 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/03 17:11:40 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/**
 * @brief Print the error message if the id line containg wrong data
 * 
 * @param id the buffer containing the id of misconfigurated line
 */
void	error_by_id(char *id)
{
	ft_putendl_fd(2, "Error");
	if (id[0] == 'A')
		ft_putstr_fd(2, "Ambient lighting ");
	else if (id[0] == 'C')
		ft_putstr_fd(2, "Camera ");
	else if (id[0] == 'L')
		ft_putstr_fd(2, "Light ");
	else if (!ft_strncmp(id, "sp", 2))
		ft_putstr_fd(2, "Sphere ");
	else if (!ft_strncmp(id, "pl", 2))
		ft_putstr_fd(2, "Planbe ");
	else if (!ft_strncmp(id, "cy", 2))
		ft_putstr_fd(2, "Cylender ");
	ft_putendl_fd(2, "line is misconfigurated");
}


void	print_message(char *id)
{
	if (errno == ENOMEM)
	{
		ft_putendl_fd(2, "Error\nMalloc failed for ");
		ft_putstr_fd(2, id);
		ft_putendl_fd(2, " line");
	}
	else if (errno == ERANGE)
	{
		ft_putendl_fd(2, "Error\nCheck range limits for ");
		ft_putstr_fd(2, id);
		ft_putendl_fd(2, " line");
	}
}

void	manage_exctract_error(t_scene *scene, char *id, bool message)
{
	t_obj	*to_free;

	if (message)
		print_message(id);
	if (scene->object)
	{
		while (scene->object != NULL)
		{
			to_free = scene->object->next;
			if (scene->object)
			{
				if (scene->object->id)
					free(scene->object->id);
				free(scene->object);
			}
			scene->object = to_free;
		}
	}
}

/**
 * @brief If an error occure during the parsing/excrating file while
 * using get_next_line, try to close the fd and free the buffer
 * 
 * @param fd the supposed rt_file file
 * @param line the gnl line
 */
void	manage_gnl_error(int fd, char *line, t_scene *scene)
{
	if (fd)
		close(fd);
	if (line)
		free(line);
	manage_exctract_error(scene, 0, false);
}
