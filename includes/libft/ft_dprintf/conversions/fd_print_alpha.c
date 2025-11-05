/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:36:28 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/05 15:58:15 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	print_string_fd(int fd, char *str)
{
	char	*dup;
	int		i;

	dup = str;
	if (!dup)
	{
		ft_putstr_fd(fd, "(null)");
		return (6);
	}
	i = ft_strlen(dup);
	ft_putstr_fd(fd, dup);
	return (i);
}

int	print_char_fd(int fd, int c)
{
	ft_putchar_fd(fd, c);
	return (1);
}

int	print_ptr_fd(int fd, void	*ptr)
{
	int			size;
	uintptr_t	adrr;

	if (ptr == NULL)
	{
		ft_putstr_fd(fd, "(nil)");
		return (5);
	}
	adrr = (uintptr_t)ptr;
	size = d_ptr_size(adrr);
	ft_putstr_fd(fd, "0x");
	print_adress_fd(fd, adrr);
	return (size + 2);
}
