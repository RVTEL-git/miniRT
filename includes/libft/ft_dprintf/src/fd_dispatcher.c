/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:07:45 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/05 15:58:20 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	d_handle_convertion(int fd, char specifier, va_list args)
{
	int		count;

	count = 0;
	if (specifier == '%')
	{
		ft_putchar_fd(fd, '%');
		return (1);
	}
	else if (specifier == 'd' || specifier == 'i')
		count = print_num_fd(fd, va_arg(args, int));
	else if (specifier == 'u')
		count = print_unit_fd(fd, va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count = print_x_fd(fd, va_arg(args, unsigned int), specifier);
	else if (specifier == 's')
		count = print_string_fd(fd, va_arg(args, char *));
	else if (specifier == 'c')
		count = print_char_fd(fd, va_arg(args, int));
	else if (specifier == 'p')
		count = print_ptr_fd(fd, va_arg(args, void *));
	return (count);
}
