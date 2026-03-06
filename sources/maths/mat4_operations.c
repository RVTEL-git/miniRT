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

	ft_memset(&m, 0, sizeof(t_mat4));
	if (axis == X)
	{
		m.m[0][0] = 1.;
		m.m[3][3] = 1.;
		m.m[1][1] = cos(n);
		m.m[1][2] = -sin(n);
		m.m[2][1] = sin(n);
		m.m[2][2] = cos(n);
	}
	else if (axis == Y)
	{
		m.m[1][1] = 1.;
		m.m[3][3] = 1.;
		m.m[0][0] = cos(n);
		m.m[0][2] = sin(n);
		m.m[2][0] = -sin(n);
		m.m[2][2] = cos(n);
	}
	else if (axis == Z)
	{
		return ((t_mat4){{{cos(n), -sin(n), 0.0, 0.0}, {sin(n), cos(n), 0.0,
			0.0}, {0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0}}});
	}
	return (m);
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

static float	compute_determinant(t_mat4 m)
{
	float	det;

	det = m.m[0][0] * (m.m[1][1] * m.m[2][2] - m.m[1][2] * m.m[2][1])
		- m.m[0][1] * (m.m[1][0] * m.m[2][2] - m.m[1][2] * m.m[2][0])
		+ m.m[0][2] * (m.m[1][0] * m.m[2][1] - m.m[1][1] * m.m[2][0]);
	return (det);
}

static t_mat4	inverse_submatrix(t_mat4 m, float det_inv)
{
	t_mat4	inv;

	inv = mat4_identity();
	inv.m[0][0] = (m.m[1][1] * m.m[2][2] - m.m[1][2] * m.m[2][1]) * det_inv;
	inv.m[0][1] = -(m.m[0][1] * m.m[2][2] - m.m[0][2] * m.m[2][1]) * det_inv;
	inv.m[0][2] = (m.m[0][1] * m.m[1][2] - m.m[0][2] * m.m[1][1]) * det_inv;
	inv.m[1][0] = -(m.m[1][0] * m.m[2][2] - m.m[1][2] * m.m[2][0]) * det_inv;
	inv.m[1][1] = (m.m[0][0] * m.m[2][2] - m.m[0][2] * m.m[2][0]) * det_inv;
	inv.m[1][2] = -(m.m[0][0] * m.m[1][2] - m.m[0][2] * m.m[1][0]) * det_inv;
	inv.m[2][0] = (m.m[1][0] * m.m[2][1] - m.m[1][1] * m.m[2][0]) * det_inv;
	inv.m[2][1] = -(m.m[0][0] * m.m[2][1] - m.m[0][1] * m.m[2][0]) * det_inv;
	inv.m[2][2] = (m.m[0][0] * m.m[1][1] - m.m[0][1] * m.m[1][0]) * det_inv;
	return (inv);
}

/**

	* @brief Build the inverse matrix with the affine transformation method (the fastest from my researchs).
 * First you extract the top left 3x3 matrix,
	then compute the determinant of this A submatrix.
 * Checks if the matrix is invertible,
	then invert the submatrix and in the end invert translation
 * TLDR :
 * the order to transform from object view to world is Transform -> Rotation z
	-> R y -> R x -> Scale
 * and so the order to transform from world to object (inverse matrix) is Sc^-1
	-> Rx^-1 -> Ry^-1 -> Rz^-1 -> Tr^-1
 *
 * @param m
 * @return
 */
t_mat4	mat4_inverse(t_mat4 m)
{
	t_mat4	inv;
	float	det;
	float	det_inv;

	det = compute_determinant(m);
	if (fabsf(det) < 1e-8f)
	{
		return (mat4_identity());
	}
	det_inv = 1.0f / det;
	inv = inverse_submatrix(m, det_inv);
	m.m[0][3] = m.m[0][3];
	m.m[1][3] = m.m[1][3];
	m.m[2][3] = m.m[2][3];
	inv.m[0][3] = -(inv.m[0][0] * m.m[0][3] + inv.m[0][1] * m.m[1][3]
			+ inv.m[0][2] * m.m[2][3]);
	inv.m[1][3] = -(inv.m[1][0] * m.m[0][3] + inv.m[1][1] * m.m[1][3]
			+ inv.m[1][2] * m.m[2][3]);
	inv.m[2][3] = -(inv.m[2][0] * m.m[0][3] + inv.m[2][1] * m.m[1][3]
			+ inv.m[2][2] * m.m[2][3]);
	return (inv);
}
