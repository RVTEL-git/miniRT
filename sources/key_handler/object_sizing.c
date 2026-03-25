/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_sizing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:48:35 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/25 22:22:07 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	size_cyl_height(t_global *data, int keysym)
{
	if (keysym == XK_9)
	{
		if (data->interface.current_obj->height - DEFAULT_SIZE_MOD > 0)
		{
			data->interface.current_obj->height -= DEFAULT_SIZE_MOD;
			ft_printf("Cylinder height decreased\n");
		}
		else
			ft_printf("Cylinder height cannot be negative\n");
	}
	else if (keysym == XK_0)
	{
		if (data->interface.current_obj->height + DEFAULT_SIZE_MOD < (INT_MAX
				- 1))
		{
			data->interface.current_obj->height += DEFAULT_SIZE_MOD;
			ft_printf("Cylinder height increased\n");
		}
		else
			ft_printf("Cylinder height is at maximum\n");
	}
}

static void	size_cyl(t_global *data, int keysym)
{
	if (keysym == XK_minus)
	{
		if (data->interface.current_obj->rad - DEFAULT_SIZE_MOD > 0)
		{
			data->interface.current_obj->rad -= DEFAULT_SIZE_MOD;
			ft_printf("Cylinder diameter decreased\n");
		}
		else
			ft_printf("Cylinder diameter cannot be negative\n");
	}
	else if (keysym == XK_equal)
	{
		if (data->interface.current_obj->rad + DEFAULT_SIZE_MOD < (INT_MAX - 1))
		{
			data->interface.current_obj->rad += DEFAULT_SIZE_MOD;
			ft_printf("Cylinder diameter increased\n");
		}
		else
			ft_printf("Cylinder diameter is at maximum\n");
	}
	else
		size_cyl_height(data, keysym);
}

static void	size_sph(t_global *data, int keysym)
{
	if (keysym == XK_9 || keysym == XK_0)
	{
		ft_printf("Current Element is not a cylinder\n");
		return (print_status(data));
	}
	if (keysym == XK_minus)
	{
		if (data->interface.current_obj->rad - DEFAULT_SIZE_MOD > 0)
		{
			data->interface.current_obj->rad -= DEFAULT_SIZE_MOD;
			ft_printf("Sphere diameter decreased\n");
		}
		else
			ft_printf("Sphere diameter cannot be negative\n");
	}
	else
	{
		if (data->interface.current_obj->rad + DEFAULT_SIZE_MOD < (INT_MAX - 1))
		{
			data->interface.current_obj->rad += DEFAULT_SIZE_MOD;
			ft_printf("Sphere diameter increased\n");
		}
		else
			ft_printf("Sphere diameter is at maximum\n");
	}
}

void	change_size(t_global *data, int keysym)
{
	if (!ft_strcmp(data->interface.current_obj->id, "cy"))
		size_cyl(data, keysym);
	else if (!ft_strcmp(data->interface.current_obj->id, "sp"))
		size_sph(data, keysym);
	else
		return (ft_printf("Current Element is neither a cylinder or a sphere\n"),
			print_status(data));
}
