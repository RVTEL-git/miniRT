/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:19:16 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/28 23:41:38 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
