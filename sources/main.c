/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:57:32 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/30 11:44:50 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int ac, char **av)
{
	t_mlx_data	data;

	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "test"))
		{
			if (!init_mlx_struct(&data))
			{
				ft_dprintf(2, "Error\nInit MLX failed\n");
				return (EXIT_FAILURE);
			}
			init_mlx_struct(&data);
		}
		else if (!init_struct(av[1]))
		{
			ft_dprintf(2, "Error\narg\n");
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
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
