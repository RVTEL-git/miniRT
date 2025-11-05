/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:24:40 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/05 18:10:43 by barmarti         ###   ########.fr       */
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
	char	*elem;

	if (id[0] == 'A')
		elem = "Ambient lighting";
	else if (id[0] == 'C')
		elem = "Camera";
	else if (id[0] == 'L')
		elem = "Light";
	else if (id[0] == 's')
		elem = "Sphere";
	else if (id[0] == 'p')
		elem = "Plane";
	else
		elem = "Cylinder";
	ft_dprintf(2, "Error\n%s line is misconfigurated\n", elem);
}

void	print_message(char *id)
{
	char	*elem;

	if (id[0] == 'A')
		elem = "Ambient lighting";
	else if (id[0] == 'C')
		elem = "Camera";
	else if (id[0] == 'L')
		elem = "Light";
	else if (id[0] == 's')
		elem = "Sphere";
	else if (id[0] == 'p')
		elem = "Plane";
	else
		elem = "Cylinder";
	if (errno == ENOMEM)
		ft_dprintf(2, "Error\nMalloc failed for %s line\n", elem);
	else if (errno == ERANGE)
		ft_dprintf(2, "Error\nCheck range limits for %s element\n", elem);
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
	line = get_next_line(fd, true);
	free(line);
	manage_exctract_error(scene, 0, false);
}
