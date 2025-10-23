/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:07:53 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/08 16:03:45 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_content(t_gnl_list **lst, int fd)
{
	int		read_v;
	char	*buff;

	while (!is_nl(*lst))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return ;
		read_v = read(fd, buff, BUFFER_SIZE);
		if (read_v <= 0)
		{
			free(buff);
			return ;
		}
		buff[read_v] = '\0';
		make_list(lst, buff);
		free(buff);
	}
}

void	clean_lst(t_gnl_list **list)
{
	t_gnl_list	*last;
	t_gnl_list	*n_node;
	char		*rem;
	int			i;

	i = 0;
	n_node = NULL;
	rem = NULL;
	if (!list || !*list)
		return ;
	last = *list;
	while (last->next)
		last = last->next;
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n' && last->content[i + 1])
	{
		rem = dup_line(last->content + i + 1);
		n_node = new_node(rem);
	}
	free_lst(list, n_node, rem);
}

void	free_lst(t_gnl_list **lst, t_gnl_list *new, char *rem)
{
	t_gnl_list	*curr;
	t_gnl_list	*next;

	if (!*lst || !lst)
		return ;
	curr = *lst;
	while (curr)
	{
		next = curr->next;
		free(curr->content);
		free(curr);
		curr = next;
	}
	*lst = new;
	if (!new)
		free(rem);
}

char	*make_new_line(t_gnl_list *lst, int len)
{
	char			*new_line;
	t_gnl_list		*curr;
	int				i;
	int				j;

	curr = lst;
	j = 0;
	new_line = malloc((sizeof(char) * len) + 1);
	if (!new_line)
		return (NULL);
	while (curr)
	{
		i = 0;
		while (curr->content[i] && curr->content[i] != '\n')
			new_line[j++] = curr->content[i++];
		if (curr->content[i] == '\n')
		{
			new_line[j++] = '\n';
			break ;
		}
		curr = curr->next;
	}
	new_line[j] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*lsts[MAX_FD];
	char				*line;
	int					index_nl;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free_lst(&lsts[fd], NULL, NULL);
		return (NULL);
	}
	get_content(&lsts[fd], fd);
	if (!lsts[fd])
		return (NULL);
	index_nl = gnl_get_len(lsts[fd]);
	line = make_new_line(lsts[fd], index_nl);
	if (!line)
	{
		free_lst(&lsts[fd], NULL, NULL);
		return (NULL);
	}
	clean_lst(&lsts[fd]);
	return (line);
}
