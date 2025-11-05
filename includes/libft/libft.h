/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:04:52 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/05 16:06:23 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>
# include <stdbool.h>
# include <errno.h>
# include <float.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "ft_dprintf/ft_dprintf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*previous;
}	t_dble_list;

char		*ft_itoa(int n);
double		ft_atof(const char *nptr);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *src);
char		*ft_strndup(char *src, int n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strnstr(const char *needle, const char *haystack, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_isalpha(int c);
int			ft_abs(int n);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_isascii(int c);
int			ft_isfloat(char *line, int charset);
int			ft_isdigit(int c);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_lstsize(t_dble_list *lst);
bool		ft_isspace(int c);
long		ft_atoi(const char *nptr);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *p, int value, size_t len);
void		ft_putchar_fd(int fd, char c);
void		ft_putstr_fd(int fd, char *s);
void		ft_putendl_fd(int fd, char *s);
void		*ft_memcpy(void *destination, const void *source, size_t size);
void		*ft_calloc(size_t elem_c, size_t elem_s);
void		ft_bzero(void *s, size_t n);
void		ft_putnbr_fd(int fd, int n);
void		ft_lstadd_front(t_dble_list **lst, t_dble_list *new);
void		ft_lstadd_back(t_dble_list **lst, t_dble_list *new);
void		ft_lstdelone(t_dble_list *lst);
void		ft_lstclear(t_dble_list *lst);
void		ft_lstiter(t_dble_list *lst, void (*f)(int));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t		ft_strlcat(char *dest, const char *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);
size_t		ft_strlen(const char *s);
t_dble_list	*ft_lstnew(int content);
t_dble_list	*ft_lstlast(t_dble_list *lst);

#endif
