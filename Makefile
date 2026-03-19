# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 10:46:18 by barmarti          #+#    #+#              #
#    Updated: 2026/03/19 17:50:59 by barmarti         ###   ########.fr        #
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
PARS = $(SRCS_DIR)/$(PARS_DIR)/parsing.c			\
		$(SRCS_DIR)/$(PARS_DIR)/pars_by_id.c		\
		$(SRCS_DIR)/$(PARS_DIR)/pars_by_id_2.c		\
		$(SRCS_DIR)/$(PARS_DIR)/pars_by_id_utils.c
		
INIT_DIR = init
GEO_DIR = geometry
MLX_INIT_DIR = mlx
LGH_DIR = light
INIT = $(SRCS_DIR)/$(INIT_DIR)/$(GEO_DIR)/init.c				\
		$(SRCS_DIR)/$(INIT_DIR)/$(GEO_DIR)/init_by_id.c			\
		$(SRCS_DIR)/$(INIT_DIR)/$(GEO_DIR)/init_by_id_2.c		\
		$(SRCS_DIR)/$(INIT_DIR)/$(GEO_DIR)/init_by_id_utils.c	\
		$(SRCS_DIR)/$(INIT_DIR)/$(GEO_DIR)/init_by_id_utils_2.c	\
		$(SRCS_DIR)/$(INIT_DIR)/$(GEO_DIR)/init_utils.c			\
		$(SRCS_DIR)/$(INIT_DIR)/$(MLX_INIT_DIR)/mlx_init.c		\
		$(SRCS_DIR)/$(INIT_DIR)/$(MLX_INIT_DIR)/mlx_handler.c	\
		$(SRCS_DIR)/$(INIT_DIR)/$(LGH_DIR)/init_light.c

REN_DIR = render
HIT_DIR = hitable
RGB_DIR = rgb
CAM_DIR = camera
REN = $(SRCS_DIR)/$(REN_DIR)/create_mlx_render.c			\
	  $(SRCS_DIR)/$(REN_DIR)/render.c						\
	  $(SRCS_DIR)/$(REN_DIR)/render_utils.c						\
	  $(SRCS_DIR)/$(REN_DIR)/$(HIT_DIR)/hit_sphere.c		\
	  $(SRCS_DIR)/$(REN_DIR)/$(HIT_DIR)/hit_cylinder.c		\
	  $(SRCS_DIR)/$(REN_DIR)/$(HIT_DIR)/hit_plane.c			\
	  $(SRCS_DIR)/$(REN_DIR)/$(HIT_DIR)/hit_obj.c			\
	  $(SRCS_DIR)/$(REN_DIR)/$(RGB_DIR)/get_color.c			\
	  $(SRCS_DIR)/$(REN_DIR)/$(RGB_DIR)/color_ray.c			\
	  $(SRCS_DIR)/$(REN_DIR)/$(RGB_DIR)/get_color_utils.c	\
	  $(SRCS_DIR)/$(REN_DIR)/$(CAM_DIR)/camera.c			\
	  $(SRCS_DIR)/$(REN_DIR)/$(CAM_DIR)/camera_utils.c


MATH_DIR = maths
MATH = $(SRCS_DIR)/$(MATH_DIR)/vec3_operations.c \
	   $(SRCS_DIR)/$(MATH_DIR)/vec3_operations2.c \
	   $(SRCS_DIR)/$(MATH_DIR)/mat4_operations.c \
	   $(SRCS_DIR)/$(MATH_DIR)/get_normal.c

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
