/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:56:53 by egiraud           #+#    #+#             */
/*   Updated: 2025/11/30 11:17:35 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "minirt.h"

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}t_vec3,	t_point;

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
