/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:40:20 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/05 15:53:46 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

# include "../libft.h"

int		d_handle_convertion(int fd, char specifier, va_list args);
int		print_hex_fd(int fd, unsigned int nbr, char c);
int		ft_dprintf(int fd, const char *format, ...);
int		print_x_fd(int fd, int x, char specifier);
int		print_unit_fd(int fd, unsigned int uni);
int		d_get_size(long nb, long base);
int		d_ptr_size(uintptr_t ptr);
int		print_string_fd(int fd, char *str);
int		print_ptr_fd(int fd, void *ptr);
int		print_char_fd(int fd, int c);
int		print_num_fd(int fd, int i);

void	print_unsigned_fd(int fd, unsigned int nb);
void	print_adress_fd(int fd, uintptr_t adress);

#endif
