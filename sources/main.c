/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:57:32 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/21 22:50:34 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_flags(char **av, t_global *global)
{
	int	i;

	i = 2;
	while (av[i])
	{
		if (!ft_strcmp(av[i], "-fs"))
			global->scene.fullscreen = true;
		else if (!ft_strcmp(av[i], "-aa"))
			global->scene.antialiasing = true;
		else
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_global	minirt;

	if (ac >= 2 && ac <= 4)
	{
		ft_bzero(&minirt.scene, sizeof(t_scene));
		ft_bzero(&minirt.mlx, sizeof(t_mlx_data));
		if (ac == 3 || ac == 4)
			if (check_flags(av, &minirt) == 1)
				return (ft_dprintf(2, "Error\nArguments or flags invalid\n%s",
						USAGE), EXIT_FAILURE);
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
		return (ft_dprintf(2, "Error\nWrong number of arguments\n%s", USAGE),
			EXIT_FAILURE);
}
