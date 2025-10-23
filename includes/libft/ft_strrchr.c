/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:10:16 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/07 11:10:19 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			index = i + 1;
		i++;
	}
	if (index >= 1)
		return ((char *)&s[index - 1]);
	else if ((unsigned char)c == 0)
		return ((char *)&s[i]);
	else
		return (NULL);
}
