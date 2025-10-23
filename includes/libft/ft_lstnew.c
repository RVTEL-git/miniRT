/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:20:44 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/08 09:59:19 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dble_list	*ft_lstnew(int content)
{
	t_dble_list	*new;

	new = malloc(sizeof(t_dble_list));
	if (!new)
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}
