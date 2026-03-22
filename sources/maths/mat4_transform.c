/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 01:58:37 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/22 23:37:48 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mat4	mat4_identity(void)
{
	t_mat4	m;

	ft_memset(&m, 0, sizeof(t_mat4));
	m.m[0][0] = 1.0;
	m.m[1][1] = 1.0;
	m.m[2][2] = 1.0;
	m.m[3][3] = 1.0;
	return (m);
}

t_mat4	mat4_translate(double x, double y, double z)
{
	t_mat4	m;

	ft_memset(&m, 0, sizeof(t_mat4));
	m.m[0][3] = x;
	m.m[1][3] = y;
	m.m[2][3] = z;
	m.m[3][3] = 1.0;
	return (m);
}

t_mat4	mat4_scale(double x, double y, double z)
{
	t_mat4	m;

	m = mat4_identity();
	m.m[0][0] = x;
	m.m[1][1] = y;
	m.m[2][2] = z;
	return (m);
}

// tout passer en comme z
t_mat4	mat4_rotate(double n, t_axis axis)
{
	t_mat4	m;
	double	c;
	double	s;

	ft_memset(&m, 0, sizeof(t_mat4));
	c = cos(n);
	s = sin(n);
	if (axis == X)
	{
		return ((t_mat4){{{1.0, 0.0, 0.0, 0.0}, {0.0, c, -s, 0.0},
				{0.0, s, c, 0.0}, {0.0, 0.0, 0.0, 1.0}}});
	}
	else if (axis == Y)
	{
		return ((t_mat4){{{c, 0.0, s, 0.0}, {0.0, 1.0, 0.0, 0.0},
				{-s, 0.0, c, 0.0}, {0.0, 0.0, 0.0, 1.0}}});
	}
	else if (axis == Z)
	{
		return ((t_mat4){{{c, -s, 0.0, 0.0}, {s, c, 0.0,
					0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}});
	}
	return (mat4_identity());
}

