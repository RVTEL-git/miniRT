/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:16:44 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/28 23:17:15 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isfloat(char *line, int charset)
{
	int	index;

	index = 0;
	if (line[index] && line[index] == '-')
		index++;
	while (line[index] && ft_isdigit(line[index]))
		index++;
	if (line[index] && line[index] == '.')
		index++;
	else
		return (0);
	if (line[index] && ft_isdigit(line[index]))
		index++;
	else
		return (0);
	while (line[index] && ft_isdigit(line[index]) && !ft_isspace(line[index]))
		index++;
	if (line[index] && charset && line[index] == charset)
		return (index);
	if (!line[index] || (line[index] && ft_isspace(line[index])))
		return (index);
	return (0);
}