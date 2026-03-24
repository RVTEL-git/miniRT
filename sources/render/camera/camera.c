/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:34:02 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/22 23:03:48 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "matrices.h"
#include "vector.h"

/**
 * @brief Build a look at matrix by processing first the axis based on normalized forward and the world up vector. From that build right and up then fill the matrix with the normalized axis vectors correctly, so that rays traced from the camera view are correctly materialized into world view
 *
 * @param orig Camera origin/point of view
 * @param dir Towards where the camera is looking
 * @return The built look at matrix
 */
t_mat4	mat4_look_at(t_vec3 orig, t_vec3 dir)
{
	t_vec3	forward;
	t_vec3	right;
	t_vec3	up;
	t_vec3	world_up;
	t_mat4	m;

	forward = vec3_normalize(dir);
	world_up = vec3_set(0, 1, 0);
	if (fabs(vec3_dot(forward, world_up)) > 0.999)
		world_up = vec3_set(0, 0, 1);
	right = vec3_normalize(vec3_cross(world_up, forward));
	up = vec3_cross(forward, right);
	m = mat4_identity();
	m.m[0][0] = right.x;
	m.m[1][0] = right.y;
	m.m[2][0] = right.z;
	m.m[0][1] = up.x;
	m.m[1][1] = up.y;
	m.m[2][1] = up.z;
	m.m[0][2] = forward.x;
	m.m[2][2] = forward.z;
	m.m[1][2] = forward.y;
	m.m[0][3] = orig.x;
	m.m[1][3] = orig.y;
	m.m[2][3] = orig.z;
	return (m);
}

/* generate a random floating point number from min to max */
double	randfrom(double min, double max)
{
	double	range;
	double	div;

	range = (max - min);
	div = RAND_MAX / range;
	return (min + (rand() / div));
}

t_ray	generate_ray(t_cam *cm, double x, double y, bool fixed)
{
	t_ray	ray;
	double	px;
	double	py;

	x += (randfrom(-0.5, 0.5) * !fixed) + (0.5 * fixed);
	y += (randfrom(-0.5, 0.5) * !fixed) + (0.5 * fixed);
	px = (2 * ((x) / cm->scrn_width) - 1) * cm->asp_ratio * cm->fov_scaled;
	py = (1 - 2 * ((y) / cm->scrn_height)) * cm->fov_scaled;
	ray.orig = mat4_apply_translation(cm->trnsf, vec3_set(0, 0, 0));
	ray.dir = vec3_normalize \
		(mat4_apply(cm->trnsf, vec3_set(px, py, 1)));
	return (ray);
}

t_mat4	build_camera_matrix(t_cam *cam)
{
	t_vec3	orig;
	t_vec3	dir;

	orig = vec3_set(cam->pos.x, cam->pos.y, cam->pos.z);
	dir = vec3_set(cam->look.x, cam->look.y, cam->look.z);
	return (mat4_look_at(orig, dir));
}

t_cam	*init_camera(t_cam *cam, int width, int height)
{
	cam->scrn_width = (double)width;
	cam->scrn_height = (double)height;
	cam->trnsf = build_camera_matrix(cam);
	cam->asp_ratio = cam->scrn_width / cam->scrn_height;
	cam->fov_scaled = tan(cam->fov * 0.5 * M_PI / 180.0);
	return (cam);
}
