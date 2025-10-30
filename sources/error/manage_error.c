/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:24:40 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/30 15:40:19 by barmarti         ###   ########.fr       */
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

void	manage_exctract_error(t_scene *scene)
{
	(void)scene;
}

/**
 * @brief If an error occure during the parsing/excrating file while
 * using get_next_line, try to close the fd and free the buffer
 * 
 * @param fd the supposed rt_file file
 * @param line the gnl line
 */
void	manage_gnl_error(int fd, char *line)
{
	if (fd)
		close(fd);
	if (line)
		free(line);
}
