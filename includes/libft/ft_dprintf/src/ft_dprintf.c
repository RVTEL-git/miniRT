/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:08:16 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/05 16:14:43 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	print_str_fd(int fd, char *format, va_list args)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == 37 && format[i + 1])
		{
			count = count + handle_convertion(format[i + 1], args);
			i = i + 2;
		}
		else
		{
			ft_putchar_fd(fd, format[i]);
			i++;
			count++;
		}
	}
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	count = print_str_fd(fd, (char *)format, args);
	va_end(args);
	return (count);
}
