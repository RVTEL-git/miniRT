/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:36:28 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/27 21:58:47 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	char	*dup;
	int		i;

	dup = str;
	if (!dup)
	{
		ft_putstr_fd(1, "(null)");
		return (6);
	}
	i = ft_strlen(dup);
	ft_putstr_fd(1, dup);
	return (i);
}

int	print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_ptr(void	*ptr)
{
	int			size;
	uintptr_t	adrr;

	if (ptr == NULL)
	{
		ft_putstr_fd(1, "(nil)");
		return (5);
	}
	adrr = (uintptr_t)ptr;
	size = ptr_size(adrr);
	ft_putstr_fd(1, "0x");
	print_adress(adrr);
	return (size + 2);
}
