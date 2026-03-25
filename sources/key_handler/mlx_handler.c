/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:07:06 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/25 19:29:45 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Display info about the currently selected element and 
 * transformation mode
 */
void	print_status(t_global *data)
{
	t_obj	*obj;

	obj = data->interface.current_obj;
	if (data->interface.mode == 0)
		ft_printf("Current Element : %s color \
%d,%d,%d\nTranformation Mode : Translation\n", obj->id, (int)obj->rgb.rd,
			(int)obj->rgb.grn, (int)obj->rgb.blu);
	else
		ft_printf("Current Element : %s color \
%d,%d,%d\nTranformation Mode : Rotation\n", obj->id, (int)obj->rgb.rd,
			(int)obj->rgb.grn, (int)obj->rgb.blu);
}

static void	change_transfo_mode(int keysym, t_global *data)
{
	if (keysym == XK_t)
	{
		data->interface.mode = 0;
		print_status(data);
	}
	else if (keysym == XK_r)
	{
		data->interface.mode = 1;
		print_status(data);
	}
}

/**
 * @brief Main distribution input
 */
static int	handle_input(int keysym, t_global *data)
{
	if (keysym == XK_Escape)
		close_mlx(data, EXIT_SUCCESS);
	else if (keysym == XK_h)
		ft_printf(COMMANDS);
	else if (keysym == XK_n || keysym == XK_p)
		change_object(data, keysym);
	else if (keysym == XK_t)
		change_transfo_mode(keysym, data);
	else if (keysym == XK_r)
		change_transfo_mode(keysym, data);
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

/**
 * @brief Initialise mlx_data struct and interface, then call key hooks so 
 * that they wait for user inputs 
 */
void	init_handler(t_global *minirt)
{
	t_mlx_data	*data;
	t_interface	interface;

	data = minirt->mlx;
	interface.first_obj = minirt->scene.object;
	interface.current_obj = minirt->scene.object;
	interface.mode = 0;
	minirt->interface = interface;
	mlx_hook(data->win_ptr, 17, 0, &close_mlx, minirt);
	mlx_key_hook(data->win_ptr, &handle_input, minirt);
}
