/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:57:01 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/28 21:09:15 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
