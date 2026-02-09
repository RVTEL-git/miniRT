/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 01:58:37 by egiraud           #+#    #+#             */
/*   Updated: 2026/02/07 16:40:44 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
	double c;
	double s;

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

t_mat4	mat4_inverse(t_mat4 m)
{


}
