/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:44:13 by ratel             #+#    #+#             */
/*   Updated: 2026/03/19 17:45:54 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	ret = vec3_clamp(get_final(ambient, diffuse, specular), 0, 1);
	ret = vec3_clamp(ret, 0, 1);
	return (ret);
}

int	sum_rgb(t_rgb *colors, size_t len)
{
	t_rgb	sum;
	size_t	time;

	time = 0;
	sum = vec3_set(0, 0, 0);
	while (time < len)
	{
		sum.rd += colors[time].rd;
		sum.grn += colors[time].grn;
		sum.blu += colors[time].blu;
		time++;
	}
	sum.rd /= len;
	sum.grn /= len;
	sum.blu /= len;
	return (s_rgb_to_int(sum));
}

t_rgb	get_rgb(t_hit_data *hit, t_scene *scene)
{
	if (hit->did_hit == true)
		return (apply_light(hit, scene));
	else
		return (vec3_set(0, 0, 0));
}
