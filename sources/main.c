/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratel <ratel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:57:32 by barmarti          #+#    #+#             */
/*   Updated: 2026/02/28 14:47:40 by ratel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_global	minirt;

	if (ac == 2)
	{
		ft_bzero(&minirt.scene, sizeof(t_scene));
		ft_bzero(&minirt.mlx, sizeof(t_mlx_data));
		if (!init_struct(av[1], &minirt.scene))
			return (EXIT_FAILURE);
		if (!init_mlx_struct(&minirt))
		{
			ft_lstclear_obj(minirt.scene.object);
			return (EXIT_FAILURE);
		}
		start_render(&minirt);
		close_mlx(&minirt, EXIT_SUCCESS);
	}
	else
	{
		return (EXIT_FAILURE);
		ft_dprintf(2, "Error\nWrong number of arguments\n");
	}
}

//pour test des trucs
// int main(void)
// {
// 	t_mlx_data mlx;
// 	//t_scene scene;

// 	init_mlx_struct(&mlx);
// }
