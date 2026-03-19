/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:01:11 by ratel             #+#    #+#             */
/*   Updated: 2026/03/19 17:24:57 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_in_shadow(t_scene *scene, t_hit_data *hit)
{
	t_ray		sha_r;
	t_hit_data	shadow_hit;
	double		light_dist;
	t_vec3		to_light;

	memset(&shadow_hit, 0, sizeof(t_hit_data));
	to_light = vec3_sub(scene->light.point, hit->p);
	light_dist = vec3_distance(scene->light.point, hit->p);
	sha_r.orig = vec3_add(hit->p, vec3_scale(hit->normal.compute, EPS * 10.0));
	sha_r.dir = vec3_normalize(to_light);
	hit_obj(sha_r, scene, &shadow_hit);
	if (shadow_hit.did_hit && shadow_hit.t > EPS && shadow_hit.t < light_dist)
		return (true);
	return (false);
}

t_rgb	init_ambient(t_hit_data *hit, t_scene *scn)
{
	t_rgb	ret;
	t_amb	a;

	a = scn->a_light;
	ret = vec3_set(0, 0, 0);
	ret.rd = (hit->obj->rgb.rd / 255) * (a.rgb.rd / 255) * a.ratio;
	ret.grn = (hit->obj->rgb.grn / 255) * (a.rgb.grn / 255) * a.ratio;
	ret.blu = (hit->obj->rgb.blu / 255) * (a.rgb.blu / 255) * a.ratio;
	return (ret);
}

t_rgb	init_diffuse(t_hit_data *hit, t_scene *scene)
{
	t_rgb	r;
	double	dot_p;
	t_vec3	p_to_light;
	t_light	l;
	t_rgb	t;

	t = hit->obj->rgb;
	l = scene->light;
	p_to_light = vec3_normalize(vec3_sub(scene->light.point, hit->p));
	dot_p = vec3_dot(p_to_light, hit->normal.compute);
	if (dot_p < 0 || is_in_shadow(scene, hit))
		r = vec3_set(0, 0, 0);
	else
	{
		r.rd = (t.rd / 255) * (l.rgb.rd / 255) * l.bright * fmax(0, dot_p);
		r.grn = (t.grn / 255) * (l.rgb.grn / 255) * l.bright * fmax(0, dot_p);
		r.blu = (t.blu / 255) * (l.rgb.blu / 255) * l.bright * fmax(0, dot_p);
	}
	return (r);
}

t_rgb	init_specular(t_hit_data *hit, t_scene *scene)
{
	t_rgb	ret;
	t_spec	spc;
	double	ndotl;
	t_vec3	r;

	spc.ks = 0.0001;
	spc.shin = 180;
	spc.p_to_light = vec3_normalize(vec3_sub(scene->light.point, hit->p));
	spc.p_to_cam = vec3_normalize(vec3_sub(scene->camera.pos, hit->p));
	ndotl = vec3_dot(hit->normal.compute, spc.p_to_light);
	if (ndotl <= 0 || is_in_shadow(scene, hit))
		ret = vec3_set(0, 0, 0);
	else
	{
		r = vec3_sub(vec3_scale(hit->normal.compute, 2.0 * ndotl), \
			spc.p_to_light);
		spc.tens = spc.ks * scene->light.bright \
				* pow(fmax(0, vec3_dot(vec3_normalize(r), \
				vec3_normalize(spc.p_to_cam))), spc.shin);
		ret = vec3_set(spc.tens * scene->light.rgb.rd / 255, \
			spc.tens * scene->light.rgb.grn / 255, \
			spc.tens * scene->light.rgb.blu / 255);
	}
	return (ret);
}
