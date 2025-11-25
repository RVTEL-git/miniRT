/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:14:48 by egiraud           #+#    #+#             */
/*   Updated: 2025/11/25 00:51:44 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vec3	vec3_set(double x, double y, double z)
{
	t_vec3	vec3;

	vec3.x = x;
	vec3.y = y;
	vec3.z = z;
	return (vec3);
}

t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3	vec3;

	vec3.x = a.x + b.x;
	vec3.y = a.y + b.y;
	vec3.z = a.z + b.z;
	return (vec3);
}

t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	vec3;

	vec3.x = a.x - b.x;
	vec3.y = a.y - b.y;
	vec3.z = a.z - b.z;
	return (vec3);
}

t_vec3	vec3_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	vec3;

	vec3.x = a.y * b.z - a.z * b.y;
	vec3.y = a.z * b.x - a.x * b.z;
	vec3.z = a.x * b.y - a.y * b.x;
	return (vec3);
}

// pas encore sur de l'utilisation
// d'ailleurs transfo les floats en double ?
double	vec3_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
