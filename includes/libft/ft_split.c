/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:47:35 by barmarti          #+#    #+#             */
/*   Updated: 2025/06/11 19:11:07 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*fill_word(const char *s, unsigned int start, int end)
{
	int		len;
	char	*sub;
	int		i;

	len = (end - start);
	sub = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static void	free_split(char **result)
{
	int	i;

	i = 0;
	if (!result)
		return ;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char	**fill_results(const char *s, char c, char **result)
{
	int	i;
	int	start;
	int	word_index;

	word_index = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[word_index] = fill_word(s, start, i);
			if (!result[word_index])
				return (free_split(result), NULL);
			word_index++;
		}
	}
	result[word_index] = NULL;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	int		count;
	char	**result;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	return (fill_results(s, c, result));
}
