/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:01:11 by ratel             #+#    #+#             */
/*   Updated: 2026/03/18 14:03:01 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_in_shadow(t_scene *scene, t_hit_data *hit)
{
	t_ray		shadow_ray;
	t_hit_data	shadow_hit;
	double		light_dist;
	t_vec3		to_light;

	memset(&shadow_hit, 0, sizeof(t_hit_data));
	to_light = vec3_sub(scene->light.point, hit->p);
	light_dist = vec3_distance(scene->light.point, hit->p);
	shadow_ray.orig = vec3_add(hit->p, vec3_scale(hit->normal.compute, EPS * 10.0));
	shadow_ray.dir = vec3_normalize(to_light);
	hit_obj(shadow_ray, scene, &shadow_hit);
	if (shadow_hit.did_hit && shadow_hit.t > EPS && shadow_hit.t < light_dist)
		return (true);
	return (false);
}

t_rgb	init_ambient(t_hit_data *hit, t_scene *scene)
{
	t_rgb	ret;

	ret = vec3_set(0, 0, 0);
	ret.red = (hit->obj->rgb.red / 255) * (scene->a_light.rgb.red / 255) * scene->a_light.amb_ratio;
	ret.green = (hit->obj->rgb.green / 255) * (scene->a_light.rgb.green / 255) * scene->a_light.amb_ratio;
	ret.blue = (hit->obj->rgb.blue/ 255) * (scene->a_light.rgb.blue / 255) * scene->a_light.amb_ratio;
	return (ret);
}

t_rgb	init_diffuse(t_hit_data *hit, t_scene *scene)
{
	t_rgb	ret;
	double	dot_p;
	t_vec3	p_to_light;

	p_to_light = vec3_normalize(vec3_sub(scene->light.point, hit->p));
	dot_p = vec3_dot(p_to_light, hit->normal.compute);
	if (dot_p < 0 || is_in_shadow(scene, hit))
		ret = vec3_set(0, 0, 0);
	else
	{
		ret.red = (hit->obj->rgb.red / 255) * (scene->light.rgb.red / 255) * scene->light.bright * fmax(0, dot_p);
		ret.green = (hit->obj->rgb.green / 255) * (scene->light.rgb.green / 255) * scene->light.bright * fmax(0, dot_p);
		ret.blue = (hit->obj->rgb.blue / 255) * (scene->light.rgb.blue / 255) * scene->light.bright * fmax(0, dot_p);
	}
	return (ret);
}

t_rgb	init_specular(t_hit_data *hit, t_scene *scene)
{
	t_rgb	ret;
	t_vec3	p_to_cam;
	double	ndotl;
	t_vec3	r;
	t_vec3	p_to_light;
	double	spec_tens;
	double	ks;
	double	shin;

	ks = 0.0001;
	shin = 180;
	p_to_light = vec3_normalize(vec3_sub(scene->light.point, hit->p));
	p_to_cam = vec3_normalize(vec3_sub(scene->camera.pos, hit->p));
	ndotl = vec3_dot(hit->normal.compute, p_to_light);
	if (ndotl <= 0 || is_in_shadow(scene, hit))
		ret = vec3_set(0, 0, 0);
	else
	{
		r = vec3_sub(vec3_scale(hit->normal.compute, 2.0 * ndotl), p_to_light);
		spec_tens = ks * scene->light.bright * pow(fmax(0, vec3_dot(vec3_normalize(r), vec3_normalize(p_to_cam))), shin);
		ret = vec3_set(spec_tens * scene->light.rgb.red / 255, spec_tens * scene->light.rgb.green / 255, spec_tens * scene->light.rgb.blue / 255);
	}
	return (ret);
}
