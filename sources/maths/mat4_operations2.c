/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:27:21 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/19 17:29:03 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

	* @brief Build the inverse matrix with the affine transformation method
	(the fastest from my researchs).
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
	if (fabsf(det) < EPS)
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
