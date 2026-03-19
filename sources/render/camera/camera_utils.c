/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:59:47 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/19 15:01:08 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "matrices.h"
#include "vector.h"

t_mat4	build_camera_matrix(t_cam *cam)
{
	t_vec3	orig;
	t_vec3	dir;

	orig = vec3_set(cam->pos.x, cam->pos.y, cam->pos.z);
	dir = vec3_set(cam->look.x, cam->look.y, cam->look.z);
	return (mat4_look_at(orig, dir));
}

/**
 * @brief Apply (multiply) the vector in the matrix so that I get 
 * rid of translation
 */
t_vec3	mat4_apply(t_mat4 m, t_vec3 p)
{
	t_vec3	r;

	r.x = m.m[0][0] * p.x + m.m[0][1] * p.y + m.m[0][2] * p.z + m.m[0][3];
	r.y = m.m[1][0] * p.x + m.m[1][1] * p.y + m.m[1][2] * p.z + m.m[1][3];
	r.z = m.m[2][0] * p.x + m.m[2][1] * p.y + m.m[2][2] * p.z + m.m[2][3];
	return (r);
}

/**
 * @brief Apply (multiply) the vector in the matrix so that I keep translation
 */
t_vec3	mat4_apply_translation(t_mat4 m, t_vec3 v)
{
	t_vec3	r;

	r.x = m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z;
	r.y = m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z;
	r.z = m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z;
	return (r);
}
