/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:57:32 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/24 15:40:43 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minirt.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!init_struct(av[1]))
			return (EXIT_FAILURE);
	}
	ft_putendl_fd(2, "Error\nWrong number of arguments");
	return (EXIT_FAILURE);
}
