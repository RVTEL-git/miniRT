/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:41:48 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/05 11:14:55 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*new_node(char	*content)
{
	t_gnl_list	*new;

	new = malloc(sizeof(t_gnl_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_gnl_list	*make_list(t_gnl_list **lst, char *buff)
{
	t_gnl_list	*curr;
	t_gnl_list	*new;

	if (!lst || !buff)
		return (NULL);
	new = new_node(dup_line(buff));
	if (!new)
	{
		free(buff);
		return (NULL);
	}
	if (!*lst)
	{
		*lst = new;
		return (*lst);
	}
	curr = *lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	return (*lst);
}

int	gnl_get_len(t_gnl_list *lst)
{
	int			i;
	int			j;
	t_gnl_list	*curr;

	curr = lst;
	i = 0;
	while (curr)
	{
		j = 0;
		while (curr->content[j])
		{
			if (curr->content[j] == '\n')
			{
				i++;
				j++;
				return (i);
			}
			i++;
			j++;
		}
		curr = curr->next;
	}
	return (i);
}

int	is_nl(t_gnl_list *lst)
{
	int			j;
	t_gnl_list	*curr;

	curr = lst;
	while (curr)
	{
		j = 0;
		while (curr->content[j])
		{
			if (curr->content[j] == '\n')
				return (1);
			j++;
		}
		curr = curr->next;
	}
	return (0);
}

char	*dup_line(char *src)
{
	char	*dup;
	int		i;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	dup = malloc((sizeof(char) * i) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
