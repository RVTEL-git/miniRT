/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_by_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:51:04 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/27 11:38:45 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../../includes/minirt.h>

bool	check_amb_line(char *line)
{
	int	index;
	int	old_index;

	index = 0;
	while (line[index])
	{
		while (ft_isspace(line[index]))
			index++;
		old_index = index;
		index = ft_isfloat(&line[index]);
		if (index == old_index)
			return (false);
		while (line[index] && ft_isspace(line[index]))
			index++;
		if (line[index] && !is_rgb(&line[index]))
			return (false);
		index++;
		while (line[index] && ft_isspace(line[index]))
			index++;
	}
	retrun (true);
}

bool	check_cam_line(char *line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		
	}
}

bool	check_light_line(char *line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		
	}
}
