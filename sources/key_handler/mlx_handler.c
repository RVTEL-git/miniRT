/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:07:06 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/22 23:50:28 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minirt.h"

void	print_status(t_global *data)
{
	t_obj	*obj;

	obj = data->interface.current_obj;
	if (data->interface.mode == 0)
		ft_printf("Current Element : %s color \
%d,%d,%d\nTranformation Mode : Translation\n", obj->id, (int)obj->rgb.rd,
			(int)obj->rgb.grn, (int)obj->rgb.blu);
	else
		ft_printf("Current Element : %s at \
%d,%d,%d\nTranformation Mode : Rotation\n", obj->id, obj->rgb.rd,
			obj->rgb.grn, obj->rgb.blu);
}

void	change_object(t_global *data, int keysym)
{
	t_obj	*obj;

	obj = data->interface.current_obj;
	if (keysym == XK_n)
	{
		obj = obj->next;
	}
	else
	{
		obj = obj->prev;
	}
	print_status(data);
}

/*void	change_object(t_global *data, int keysym)
{
	t_obj	*obj;

	obj = data->interface.current_obj;
	if (keysym == XK_n)
	{
		if (obj->next)
			obj = obj->next;
		else
			obj = data->interface.first_obj;
	}
	else
	{
		if (obj->prev)
			obj = obj->prev;
		else
			obj = ft_lstlast_obj(obj);
	}
	print_status(data);
}*/

void	change_size(t_global *data, int keysym)
{
	if (ft_strcmp(data->interface.current_obj->id, "cy")
		&& ft_strcmp(data->interface.current_obj->id, "sp"))
		return (ft_printf("Current Element is neither a cylinder or a sphere\n"),
			print_status(data));
	if (keysym == XK_minus)
	{
		data->interface.current_obj->diameter -= DEFAULT_SIZE_MOD;
		ft_printf("Object size changed\n");
	}
	else if (keysym == XK_equal)
	{
		data->interface.current_obj->diameter += DEFAULT_SIZE_MOD;
		ft_printf("Object size changed\n");
	}
	if (!ft_strcmp(data->interface.current_obj->id, "cy"))
	{
		if (keysym == XK_9)
			data->interface.current_obj->height -= DEFAULT_SIZE_MOD;
		else if (keysym == XK_0)
			data->interface.current_obj->height += DEFAULT_SIZE_MOD;
		ft_printf("Object size changed\n");
	}
	else
		if (keysym == XK_0 || keysym == XK_9)
			ft_printf("Current Element is not a cylinder\n");
}

static void	translate_object(t_global *global, int keysym)
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

static void	rotate_object(t_global *global, int keysym)
{
	t_obj	*obj;
	t_mat4	to;
	t_mat4	tb;
	t_mat4	r;
	t_mat4	m;

	obj = global->interface.current_obj;
	to = mat4_translate(-obj->pos.x, -obj->pos.y, -obj->pos.z);
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
	tb = mat4_translate(obj->pos.x, obj->pos.y, obj->pos.z);
	m = mat4_mult(tb, mat4_mult(r, to));
	obj->pos = mat4_apply_translation(m, obj->pos);
	ft_printf("Object Rotated\n");
}

void	apply_transformation(t_global *data, int keysym)
{
	if (!ft_strcmp(data->interface.current_obj->id, "sp")
		&& data->interface.mode == 1)
	{
		ft_printf("Sphere cannot be rotated");
		return ;
	}
	ft_printf("DEBUG transfo %s with mode %d\n", data->interface.current_obj->id,
		data->interface.mode);
	if (data->interface.mode == 0)
		translate_object(data, keysym);
	else
		rotate_object(data, keysym);
}

int	close_mlx(t_global *data, int code)
{
	t_mlx_data	*mlx;

	mlx = data->mlx;
	ft_lstclear_obj(data->scene.object);
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
	exit(code);
}

static int	handle_input(int keysym, t_global *data)
{
	//ft_printf("id2 %s\n", data->interface.current_obj->id);
	if (keysym == XK_Escape)
		close_mlx(data, EXIT_SUCCESS);
	else if (keysym == XK_h)
		ft_printf(COMMANDS);
	else if (keysym == XK_n || keysym == XK_p)
		change_object(data, keysym);
	else if (keysym == XK_t)
		data->interface.mode = 0;
	else if (keysym == XK_r)
		data->interface.mode = 1;
	else if (keysym == XK_9 || keysym == XK_0
		|| keysym == XK_equal || keysym == XK_minus)
		change_size(data, keysym);
	else if (keysym == XK_q || keysym == XK_w || keysym == XK_e
		|| keysym == XK_a || keysym == XK_s || keysym == XK_d)
		apply_transformation(data, keysym);
	else if (keysym == XK_space)
		render(&data->scene, data->mlx);
	return (0);
}

void	init_handler(t_global *minirt)
{
	t_mlx_data	*data;
	t_interface	interface;

	data = minirt->mlx;
	interface.first_obj = minirt->scene.object;
	interface.current_obj = minirt->scene.object;
	interface.mode = 0;
	minirt->interface = interface;
	//ft_printf("id %s\n", minirt->interface.current_obj->id);
	mlx_hook(data->win_ptr, 17, 0, &close_mlx, minirt);
	mlx_key_hook(data->win_ptr, &handle_input, minirt);
}
