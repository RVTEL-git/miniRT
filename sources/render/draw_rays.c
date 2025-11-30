/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 08:03:24 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/30 12:02:43 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

struct s_limit
{
	bool	screen_limit;

};

struct s_draw
{
	double	x;
	double	y;
};

static inline bool	reach_limits(t_mlx_data *data, struct s_draw draw)
{
	int	rect_max;
	int	rect_min;

	rect_max = 400;
	rect_min = 200;
	if ((draw.x >= rect_min && draw.x <= rect_max) && \
		(draw.y >= rect_min && draw.y <= rect_max))
		return (true);
	if (draw.x < 0 || draw.x > data->width)
		return (true);
	if (draw.y < 0 || draw.y > data->height)
		return (true);
	return (false);
}

static void	init_ray(t_ray	*ray, int pos_x, int pos_y, int ray_number)
{
	double	angle;

	ft_bzero(ray, sizeof(t_ray));
	angle = ((double) ray_number / 1000) * 2 * M_PI;
	ray->angle = angle;
	ray->orig.x = pos_x;
	ray->orig.y = pos_y;
}

void	draw_rays(t_mlx_data *dta, int pos_x, int pos_y, int color)
{
	t_ray			ray;
	int				ray_number;
	bool			limit;
	struct s_draw	drw;

	ray_number = 0;
	while (ray_number <= 1000)
	{
		init_ray(&ray, pos_x, pos_y, ray_number);
		drw.x = ray.orig.x;
		drw.y = ray.orig.y;
		limit = false;
		while (!limit)
		{
			drw.x += (double)1 * cos(ray.angle);
			drw.y += (double)1 * sin(ray.angle);
			mlx_pixel_put(dta->mlx_ptr, dta->win_ptr, drw.x, drw.y, color);
			if (reach_limits(dta, drw))
				limit = true;
		}
		ray_number++;
	}
}
