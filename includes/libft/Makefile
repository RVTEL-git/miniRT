# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 15:46:45 by cscache           #+#    #+#              #
#    Updated: 2025/10/31 13:36:50 by barmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDE = libft.h \
ft_printf/ft_printf.h \
get_next_line/get_next_line.h

SRCS = ft_memcmp.c\
ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcpy.c ft_memmove.c\
ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_atof.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_isfloat.c\
ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
ft_lstiter.c ft_abs.c ft_isspace.c ft_strndup.c \

SRC_PRINTF = ft_printf/src
CONV_DIR_PRINTF = ft_printf/conversions

SRCS_PRINTF = \
 $(SRC_PRINTF)/ft_printf.c \
 $(SRC_PRINTF)/dispatcher.c \
 $(CONV_DIR_PRINTF)/print_alpha.c \
 $(CONV_DIR_PRINTF)/print_numerals.c \
 $(CONV_DIR_PRINTF)/utils.c
 
 SRC_GNL = get_next_line
 
 SRCS_GNL = \
  $(SRC_GNL)/get_next_line.c \
  $(SRC_GNL)/get_next_line_utils.c

OBJS = $(SRCS:.c=.o) $(SRCS_PRINTF:.c=.o) $(SRCS_GNL:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I.
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS) > /dev/null

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -I. -Ift_printf -Iget_next_line -c $< -o $@ > /dev/null

clean:
	rm -f $(OBJS) > /dev/null

fclean: clean
	rm -f $(NAME) > /dev/null

re: fclean all
	
.PHONY: all clean fclean re bonus
