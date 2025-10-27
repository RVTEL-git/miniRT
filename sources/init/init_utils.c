/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:59:31 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/27 10:43:04 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../../includes/minirt.h>

bool	is_dir(char *rt_file)
{
	int	fd_rt;

	fd_rt = open(rt_file, __O_DIRECTORY);
	if (errno == ENOTDIR)
		return (false);
	close(rt_file);
	return (true);
}

static bool	is_valid_identifier(char *c, char *id)
{
	if (c[0] == 'A' || c[0] == 'C' || c[0] == 'L' && ft_isspace(c[1]))
	{
		id[0] = c[0];
		id[1] = '\0';
	}
	else if (c[0] == 's' && c[1] == 'p' && ft_isspace(c[2]))
		id = 'sp';
	else if (c[0] == 'p' && c[1] == 'l' && ft_isspace(c[2]))
		id = 'pl';
	else if (c[0] == 'c' && c[1] == 'y' && ft_isspace(c[2]))
		id = 'cy';
}

bool	is_valid(char *gnl_line)
{
	int		index;
	char	id[3];

	index = 0;
	ft_bzero(id, 3);
	while (gnl_line[index])
	{
		while (ft_isspace(gnl_line[index]))
			index++;
		is_valid_identifier(&gnl_line[index], &id);
		index++;
		if (!ft_strncmp(id, "A", 1) && !check_amb_line(&gnl_line[index]))
			return (false);
		if (!ft_strncmp(id, "C", 1) && !check_cam_line(&gnl_line[index]))
			return (false);
		if (!ft_strncmp(id, "L", 1) && !check_light_line(&gnl_line[index]))
			return (false);
		if (!ft_strncmp(id, "sp", 2) && !check_spher_line(&gnl_line[index]))
			return (false);
		if (!ft_strncmp(id, "pl", 2) && !check_plane_line(&gnl_line[index]))
			return (false);
		if (!ft_strncmp(id, "cy", 2) && !check_cylin_line(&gnl_line[index]))
			return (false);
	}
	return (true);
}
