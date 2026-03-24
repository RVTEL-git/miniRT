/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_multiply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 23:00:14 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/22 23:37:27 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Multiply two matrices with each other, order is important! 
 */
t_mat4	mat4_mult(t_mat4 a, t_mat4 b)
{
	t_mat4	m;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m.m[i][j] = a.m[i][0] * b.m[0][j] + a.m[i][1] * b.m[1][j]
				+ a.m[i][2] * b.m[2][j] + a.m[i][3] * b.m[3][j];
			j++;
		}
		i++;
	}
	return (m);
}

/**
 * @brief Apply (multiply) the vector in the matrix so that I keep translation
 * for points like position.
 */
t_vec3	mat4_apply_translation(t_mat4 m, t_vec3 p)
{
	t_vec3	r;

	r.x = m.m[0][0] * p.x + m.m[0][1] * p.y + m.m[0][2] * p.z + m.m[0][3];
	r.y = m.m[1][0] * p.x + m.m[1][1] * p.y + m.m[1][2] * p.z + m.m[1][3];
	r.z = m.m[2][0] * p.x + m.m[2][1] * p.y + m.m[2][2] * p.z + m.m[2][3];
	return (r);
}

/**
 * @brief Apply (multiply) the vector in the matrix so that I ignore 
 * translation for vectors like normals or direction vectors
 */
t_vec3	mat4_apply(t_mat4 m, t_vec3 v)
{
	t_vec3	r;

	r.x = m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z;
	r.y = m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z;
	r.z = m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z;
	return (r);
}
