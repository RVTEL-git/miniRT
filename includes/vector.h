/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:56:53 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/13 15:40:05 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector3
{
	union {
		double x;
		double red;
		double a;
	};
	union {
		double y;
		double green;
		double b;
	};
	union {
		double z;
		double blue;
		double c;
	};
}
t_equ,	t_rgb,	t_vec3,	t_point,	t_coor;

/* METHODES */

t_vec3		vec3_set(double x, double y, double z);
t_vec3		vec3_add(t_vec3 a, t_vec3 b);
t_vec3		vec3_sub(t_vec3 a, t_vec3 b);
t_vec3		vec3_cross(t_vec3 a, t_vec3 b);
double		vec3_dot(t_vec3 a, t_vec3 b);
double		vec3_magnitude(t_vec3 vec3);
t_vec3		vec3_normalize(t_vec3 vec3);
double		vec3_distance(t_vec3 a, t_vec3 b);
t_vec3		vec3_scale(t_vec3 vec3, double n);

#endif
