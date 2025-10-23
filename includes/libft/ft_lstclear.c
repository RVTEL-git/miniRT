/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:04:26 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/12 14:37:07 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_dble_list *lst)
{
	t_dble_list	*curr;

	if (!lst)
		return ;
	while (lst != NULL)
	{
		curr = lst->next;
		ft_lstdelone(lst);
		lst = curr;
	}
	lst = NULL;
}
