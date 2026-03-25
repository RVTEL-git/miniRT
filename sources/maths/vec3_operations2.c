/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:39:01 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/19 15:06:45 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Calculate the magnitude of a vector (his lenght)
 */
double	vec3_magnitude(t_vec3 vec3)
{
	return (sqrt(vec3_dot(vec3, vec3)));
}

/**
 * @brief Get a vector that is identical to the one given in input except for 
 * his norm that is set to 1
 */
t_vec3	vec3_normalize(t_vec3 vec3)
{
	double	mag;
	t_vec3	new;

	mag = vec3_magnitude(vec3);
	if (mag == 0)
		ft_printf("A directional vector is NULL, check .rt file to fix\n");
	new = vec3_set(vec3.x / mag, vec3.y / mag, vec3.z / mag);
	return (new);
}

/**
 * @brief Calculate the distance between the two ends of two given vectors
 */
double	vec3_distance(t_vec3 a, t_vec3 b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2)));
}

/**
 * @brief Scale a vector with a given number
 */
t_vec3	vec3_scale(t_vec3 vec3, double n)
{
	t_vec3	new;

	return (new = vec3_set(vec3.x * n, vec3.y * n, vec3.z * n));
}
