/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:57:01 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/27 09:48:46 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../../includes/minirt.h>

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

static bool	extract_file_data(char *rt_file, t_scene *scene)
{
	int		fd_rt;
	char	*buff_temp;

	fd_rt = open(rt_file, O_RDONLY);
	if (fd_rt < 0)
		ft_putendl_fd(2, "Error\nOpen failure");
	buff_temp = get_next_line(fd_rt);
	while (buff_temp)
	{
		if (!is_valid)
			return (false);
		
	}
	
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
	if (!extract_file_data(rt_file, &scene))
		return (false);
}
