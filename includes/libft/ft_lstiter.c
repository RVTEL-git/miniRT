/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:42:32 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/09 16:18:18 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_dble_list *lst, void (*f)(int))
{
	t_dble_list	*curr;

	if (!lst || !f)
		return ;
	curr = lst;
	while (curr != NULL)
	{
		f(curr->data);
		curr = curr->next;
	}
}
