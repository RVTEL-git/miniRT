/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:57:32 by barmarti          #+#    #+#             */
/*   Updated: 2026/02/10 11:50:47 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_global	minirt;

	if (ac == 2)
	{
		ft_bzero(&minirt.scene, sizeof(t_scene));
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
	ft_dprintf(2, "Error\nWrong number of arguments\n");
	return (EXIT_FAILURE);
}

//pour test des trucs
// int main(void)
// {
// 	t_mlx_data mlx;
// 	//t_scene scene;

// 	init_mlx_struct(&mlx);
// }
