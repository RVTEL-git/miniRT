/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 01:34:02 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/12 13:54:41 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "matrices.h"
#include "vector.h"

t_mat4 mat4_look_at(t_vec3 orig, t_vec3 dir)
{
    t_vec3 forward;
    t_vec3 right;
    t_vec3 up;
    t_vec3 world_up;
    t_mat4 m;

    forward = vec3_normalize(dir);
    world_up = vec3_set(0, 1, 0);

    // attention a si la cam regarde pile en haut ou en bas ca peut casser donc cette solution ????
    if (fabs(vec3_dot(forward, world_up)) > 0.999)
        world_up = vec3_set(0, 0, 1);

    right = vec3_normalize(vec3_cross(world_up, forward));
    up = vec3_cross(forward, right);

    m = mat4_identity();

    m.m[0][0] = right.x;
    m.m[0][1] = up.x;
    m.m[0][2] = forward.x;
    m.m[0][3] = orig.x;

    m.m[1][0] = right.y;
    m.m[1][1] = up.y;
    m.m[1][2] = forward.y;
    m.m[1][3] = orig.y;

    m.m[2][0] = right.z;
    m.m[2][1] = up.z;
    m.m[2][2] = forward.z;
    m.m[2][3] = orig.z;

    return m;
}


t_mat4 build_camera_matrix(t_cam *cam)
{
    t_vec3 orig;
    t_vec3 dir;

    orig = vec3_set(cam->pos.x, cam->pos.y, cam->pos.z);
    dir = vec3_set(cam->look.x, cam->look.y, cam->look.z);

    return mat4_look_at(orig, dir);
}

/**
 * @brief Apply (multiply) the vector in the matrix so that I get rid of translation
 */
t_vec3 mat4_apply(t_mat4 m, t_vec3 p)
{
    t_vec3 r;

    r.x = m.m[0][0]*p.x + m.m[0][1]*p.y + m.m[0][2]*p.z + m.m[0][3];
    r.y = m.m[1][0]*p.x + m.m[1][1]*p.y + m.m[1][2]*p.z + m.m[1][3];
    r.z = m.m[2][0]*p.x + m.m[2][1]*p.y + m.m[2][2]*p.z + m.m[2][3];

    return r;
}

/**
 * @brief Apply (multiply) the vector in the matrix so that I keep translation
 */
t_vec3 mat4_apply_translation(t_mat4 m, t_vec3 v)
{
    t_vec3 r;

    r.x = m.m[0][0]*v.x + m.m[0][1]*v.y + m.m[0][2]*v.z;
    r.y = m.m[1][0]*v.x + m.m[1][1]*v.y + m.m[1][2]*v.z;
    r.z = m.m[2][0]*v.x + m.m[2][1]*v.y + m.m[2][2]*v.z;

    return r;
}

t_ray generate_ray(t_cam *cam, int x, int y)
{
    t_ray ray;
    double px;
    double py;

    px = (2 * ((x + 0.5) / cam->scrn_width) - 1) * cam->aspect_ratio * cam->fov_scaled;
    py = (1 - 2 * ((y + 0.5) / cam->scrn_height)) * cam->fov_scaled;

    ray.orig = mat4_apply(cam->transform, vec3_set(0, 0, 0));
    ray.dir = vec3_normalize(mat4_apply_translation(cam->transform, vec3_set(px, py, 1)));

    return ray;
}

t_cam	*init_camera(t_cam *cam, int width, int height)
{
	cam->scrn_width = (double)width;
	cam->scrn_height = (double)height;
	cam->transform = build_camera_matrix(cam);
	cam->aspect_ratio = cam->scrn_width / cam->scrn_height;
	cam->fov_scaled = tan(cam->fov * 0.5 * M_PI / 180.0);
	return (cam);	
}
