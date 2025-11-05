/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:41:46 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/05 11:23:57 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

typedef struct s_gnl_list
{
	char				*content;
	struct s_gnl_list	*next;
}	t_gnl_list;

char			*get_next_line(int fd, bool wipe);
char			*make_new_line(t_gnl_list *lst, int i);
char			*dup_line(char *src);

int				is_nl(t_gnl_list *lst);
int				gnl_get_len(t_gnl_list *lst);

void			free_lst(t_gnl_list **list, t_gnl_list *new_node, char *rest);
t_gnl_list		*make_list(t_gnl_list **lst, char *buff);
t_gnl_list		*new_node(char	*content);

void			get_content(t_gnl_list **lst, int fd);
void			clean_lst(t_gnl_list **list);

#endif
