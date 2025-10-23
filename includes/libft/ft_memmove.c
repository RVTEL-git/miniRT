/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:17:05 by ratel             #+#    #+#             */
/*   Updated: 2025/07/03 12:21:40 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_b;
	const unsigned char	*src_b;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	dest_b = (unsigned char *)dest;
	src_b = (const unsigned char *)src;
	if (dest_b <= src_b)
	{
		ft_memcpy(dest_b, src_b, n);
	}
	else if (dest_b > src_b)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dest_b[i] = src_b[i];
		}
	}
	return (dest);
}
