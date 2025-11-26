# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 10:46:18 by barmarti          #+#    #+#              #
#    Updated: 2025/11/21 11:52:49 by barmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

NAME = miniRT

SRCS_DIR = sources
HEADER = includes/minirt.h

INCLUDES = -Iincludes -Iincludes/libft -Iincludes/libft/ft_printf -Iincludes/libft/ft_printf/src -Iincludes/libft/ft_printf/conversions -Iincludes/libft/ft_dprintf -Iincludes/libft/ft_dprintf/src -Iincludes/libft/ft_dprintf/conversions -Iincludes/minilibx-linux

MLX_DIR = includes/minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_LDFLAGS = -L$(MLX_DIR) -lXext -lX11 -lm -lz

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/DEBUG.c

PARS_DIR = parsing
PARS = $(SRCS_DIR)/$(PARS_DIR)/parsing.c \
		$(SRCS_DIR)/$(PARS_DIR)/pars_by_id.c \
		$(SRCS_DIR)/$(PARS_DIR)/pars_by_id_2.c \
		$(SRCS_DIR)/$(PARS_DIR)/pars_by_id_utils.c
		
INIT_DIR = init
GEO_DIR = geometry
WIN_DIR = window
INIT = $(SRCS_DIR)/$(INIT_DIR)/$(GEO_DIR)/init.c \
		$(SRCS_DIR)/$(INIT_DIR)/$(GEO_DIR)/init_by_id.c \
		$(SRCS_DIR)/$(INIT_DIR)/$(GEO_DIR)/init_by_id_2.c \
		$(SRCS_DIR)/$(INIT_DIR)/$(GEO_DIR)/init_by_id_utils.c \
		$(SRCS_DIR)/$(INIT_DIR)/$(GEO_DIR)/init_by_id_utils_2.c \
		$(SRCS_DIR)/$(INIT_DIR)/$(GEO_DIR)/init_utils.c \
		$(SRCS_DIR)/$(INIT_DIR)/$(WIN_DIR)/init_mlx.c 

REN_DIR = render
REN = $(SRCS_DIR)/$(REN_DIR)/draw.c \
	  $(SRCS_DIR)/$(REN_DIR)/camera.c \
	  $(SRCS_DIR)/$(REN_DIR)/render.c

MATH_DIR = maths
MATH = $(SRCS_DIR)/$(MATH_DIR)/vec3_operations.c \
	   $(SRCS_DIR)/$(MATH_DIR)/vec3_operations2.c

LST_DIR = list
LST = $(SRCS_DIR)/$(LST_DIR)/obj_list.c

ERR_DIR = error
ERR = $(SRCS_DIR)/$(ERR_DIR)/manage_error.c

SRCS_FILES = $(SRCS) $(PARS) $(INIT) $(REN) $(LST) $(ERR) $(MATH)

OBJ_DIR = obj
OBJS = $(SRCS_FILES:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_LDFLAGS) -o $(NAME)
	@echo "Compilation done"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@-$(MAKE) -C $(LIBFT_DIR) clean
	@-$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@-$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null

re: fclean all

.PHONY: all clean fclean re
