/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratel <ratel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:44:13 by ratel             #+#    #+#             */
/*   Updated: 2026/03/16 22:13:22 by ratel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_render
{
	t_vec3	p_to_light;
	
}	t_render;

static inline double clamp_scalar(double val, double min, double max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

t_vec3	vec3_clamp(t_vec3 to_clamp, double min, double max)
{
	to_clamp.a = clamp_scalar(to_clamp.a, min, max);
	to_clamp.b = clamp_scalar(to_clamp.b, min, max);
	to_clamp.c = clamp_scalar(to_clamp.c, min, max);
	return(to_clamp);
}

t_rgb	get_final(t_rgb	diffuse, t_rgb specular, t_rgb ambient)
{
	t_rgb ret;

	ret = vec3_set(0, 0, 0);
	ret = vec3_add(ambient, diffuse);
	ret = vec3_add(ret, specular);
	return (ret);
}

t_rgb	apply_light(t_hit_data *hit, t_scene *scene)
{
	t_rgb	diffuse;
	t_rgb	specular;
	t_rgb	ambient;
	t_rgb	ret;

	ambient = vec3_set(0, 0, 0);
	specular = vec3_set(0, 0, 0);
	specular = init_specular(hit, scene);
	diffuse = vec3_set(0, 0, 0);
	ambient = init_ambient(hit, scene);
	diffuse = init_diffuse(hit, scene);
	ret = get_final(ambient, diffuse, specular);
	ret = vec3_clamp(ret, 0, 1);
	return (ret);
}

int	get_rgb(t_hit_data *hit, t_scene *scene)
{
	if (hit->did_hit == true)
		return(s_rgb_to_int(apply_light(hit, scene)));
	else 
		return (BLACK_COLOR);
}
