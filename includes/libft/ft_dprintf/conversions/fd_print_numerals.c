/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_print_numerals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:05:43 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/05 16:15:40 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	print_num_fd(int fd, int i)
{
	int	size;

	size = d_get_size(i, 10);
	ft_putnbr_fd(fd, i);
	return (size);
}

int	print_unit_fd(int fd, unsigned int uni)
{
	int	size;

	size = d_get_size(uni, 10);
	print_unsigned_fd(fd, uni);
	return (size);
}

int	print_x_fd(int fd, int x, char specifier)
{
	int	size;

	size = print_hex_fd(fd, x, specifier);
	return (size);
}
