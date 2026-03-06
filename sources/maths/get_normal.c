/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:40:19 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/06 17:50:33 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	get_normal(t_vec3 p, t_obj *obj)
{
	t_vec3	ret;
	if (!ft_strcmp(obj->id, "pl"))
		ret = get_normal_plane()
	else if (!ft_strcmp(obj->id, "sp"))
		ret = get_normal_sphere()
	else if (!ft_strcmp(obj->id, "cy"))
		ret = get_normal_cylinder()
}