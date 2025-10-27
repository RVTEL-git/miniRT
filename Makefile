# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 10:46:18 by barmarti          #+#    #+#              #
#    Updated: 2025/10/27 10:14:38 by barmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = miniRT

SRCS_DIR = sources
HEADER = includes/minirt.h

INCLUDES := -Iinclude -Iinclude/libft -Iinclude/libft/ft_printf -Iinclude/libft/ft_printf/src -Iinclude/libft/ft_printf/conversions

MLX_DIR := include/minilibx-linux
MLX_LIB := $(MLX_DIR)/libmlx.a
MLX_FLAGS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT_DIR := include/libft
LIBFT := $(LIBFT_DIR)/libft.a

SRCS = $(SRCS_DIR)/main.c

# UTL_DIR = utils
# UTL = $(SRCS_DIR)/$(UTL_DIR)/ft_utils.c \
# 		$(SRCS_DIR)/$(UTL_DIR)/ft_utils_2.c

INIT_DIR = init
INIT = $(SRCS_DIR)/$(INIT_DIR)/init.c \
		$(SRCS_DIR)/$(INIT_DIR)/init_utils.c \
		$(SRCS_DIR)/$(INIT_DIR)/check_by_id.c \
		$(SRCS_DIR)/$(INIT_DIR)/check_by_id_2.c \
		$(SRCS_DIR)/$(INIT_DIR)/check_by_id_utils.c 

# SMU_DIR = simu
# SIMU = $(SRCS_DIR)/$(SMU_DIR)/launch_simu.c \
# 		$(SRCS_DIR)/$(SMU_DIR)/simu_utils.c \
# 		$(SRCS_DIR)/$(SMU_DIR)/routine_utils.c \
# 		$(SRCS_DIR)/$(SMU_DIR)/routine.c

# SRCS_FILES = $(SRCS) $(UTL) $(INIT) $(SIMU)

# OBJ_DIR = obj
# OBJS = $(SRCS_FILES:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation done"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re