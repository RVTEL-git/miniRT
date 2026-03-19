/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 01:29:58 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/19 17:29:21 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

//ptet a bouger a voir
typedef enum e_axis
{
	X,
	Y,
	Z
}t_axis;

typedef struct s_mat4
{
	double	m[4][4];	
}t_mat4;

t_mat4	mat4_identity(void);
t_mat4	mat4_translate(double x, double y, double z);
t_mat4	mat4_scale(double x, double y, double z);
t_mat4	mat4_rotate(double n, t_axis axis);
t_mat4	mat4_mult(t_mat4 a, t_mat4 b);
t_mat4	mat4_transpose(t_mat4 m);
t_mat4	mat4_inverse(t_mat4 m);

#endif
