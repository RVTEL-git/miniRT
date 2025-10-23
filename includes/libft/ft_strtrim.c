/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:41:57 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/03 13:09:59 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index_strt;
	int		index_end;
	int		i;
	char	*trim;

	index_strt = 0;
	if (!s1 || !set)
		return (0);
	while (s1[index_strt] && is_set(s1[index_strt], set))
		index_strt++;
	index_end = ft_strlen(s1);
	while (index_end > index_strt && is_set(s1[index_end - 1], set))
		index_end--;
	trim = (char *)malloc(sizeof(char) * (index_end - index_strt + 1));
	if (!trim)
		return (NULL);
	i = 0;
	while (index_strt < index_end)
		trim[i++] = s1[index_strt++];
	trim[i] = '\0';
	return (trim);
}
