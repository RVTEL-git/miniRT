/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:29:17 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/19 17:09:43 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_lstadd_back_obj(t_obj **lst, t_obj *new)
{
	t_obj	*temp;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast_obj(*lst);
	temp->next = new;
	new->prev = temp;
}

t_obj	*ft_lstlast_obj(t_obj *lst)
{
	t_obj	*curr;

	curr = lst;
	if (curr == NULL)
		return (NULL);
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

static void	ft_lstdelone_obj(t_obj *lst)
{
	if (!lst)
		return ;
	free(lst->id);
	free(lst);
}

void	ft_lstclear_obj(t_obj *lst)
{
	t_obj	*curr;

	if (!lst)
		return ;
	while (lst != NULL)
	{
		curr = lst->next;
		ft_lstdelone_obj(lst);
		lst = curr;
	}
}
