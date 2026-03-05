/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:22:49 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/04 19:50:46 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	hit_obj(t_ray ray, t_scene *scn)
{
	t_obj	*tmp;
	double	best;
	double	t;

	tmp = scn->object;
	best = -1.0;
	while (tmp)
	{
		t = -1.0;
		if (!ft_strcmp(tmp->id, "pl"))
			t = hit_plane(tmp, ray);
		else if (!ft_strcmp(tmp->id, "sp"))
			t = hit_sphere(tmp, ray);
		else if (!ft_strcmp(tmp->id, "cy"))
			t = hit_cylinder(tmp, ray);
		if (t > 0.0 && (best < 0.0 || t < best))
			best = t;
		tmp = tmp->next;
	}
	return (best);
}
