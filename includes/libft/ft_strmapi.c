/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:53:56 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/07 11:51:34 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = f(i, s[i]);
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
