/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:28:05 by egiraud           #+#    #+#             */
/*   Updated: 2026/03/25 22:22:36 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Cycle between all element in the list, in a circular way
 */
void	change_object(t_global *data, int keysym)
{
	t_interface	*itf;

	itf = &data->interface;
	if (keysym == XK_n)
	{
		if (itf->current_obj->next)
			itf->current_obj = itf->current_obj->next;
		else
			itf->current_obj = itf->first_obj;
	}
	else
	{
		if (itf->current_obj->prev)
			itf->current_obj = itf->current_obj->prev;
		else
		{
			itf->current_obj = ft_lstlast_obj(itf->current_obj);
		}
	}
	print_status(data);
}

/**
 * @brief Apply translation to current element (move object)
 */
void	translate_object(t_global *global, int keysym)
{
	t_mat4	m;

	if (keysym == XK_a)
		m = mat4_translate(-1, 0, 0);
	else if (keysym == XK_d)
		m = mat4_translate(1, 0, 0);
	else if (keysym == XK_w)
		m = mat4_translate(0, 0, 1);
	else if (keysym == XK_s)
		m = mat4_translate(0, 0, -1);
	else if (keysym == XK_q)
		m = mat4_translate(0, -1, 0);
	else
		m = mat4_translate(0, 1, 0);
	global->interface.current_obj->pos = mat4_apply_translation(m,
			global->interface.current_obj->pos);
	ft_printf("Object Moved\n");
}

/**
 * @brief Apply rotation to current element
 */
void	rotate_object(t_global *global, int keysym)
{
	t_obj	*obj;
	t_mat4	r;

	obj = global->interface.current_obj;
	if (keysym == XK_a)
		r = mat4_rotate(-DEFAULT_ROT_ANG, X);
	else if (keysym == XK_d)
		r = mat4_rotate(DEFAULT_ROT_ANG, X);
	else if (keysym == XK_w)
		r = mat4_rotate(-DEFAULT_ROT_ANG, Z);
	else if (keysym == XK_s)
		r = mat4_rotate(DEFAULT_ROT_ANG, Z);
	else if (keysym == XK_q)
		r = mat4_rotate(-DEFAULT_ROT_ANG, Y);
	else
		r = mat4_rotate(DEFAULT_ROT_ANG, Y);
	obj->v = mat4_apply(r, obj->v);
	ft_printf("Object Rotated\n");
}

/**
 * @brief Distribute to the right transformation mode
 */
void	apply_transformation(t_global *data, int keysym)
{
	if (!ft_strcmp(data->interface.current_obj->id, "sp")
		&& data->interface.mode == 1)
	{
		ft_printf("Sphere cannot be rotated");
		return ;
	}
	if (data->interface.mode == 0)
		translate_object(data, keysym);
	else
		rotate_object(data, keysym);
}
