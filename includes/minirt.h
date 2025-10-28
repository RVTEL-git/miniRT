/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:48:12 by barmarti          #+#    #+#             */
/*   Updated: 2025/10/28 23:28:44 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <errno.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"

/*=== CODE ERREUR ===*/
# define EXIT_FAILURE			1
# define EXIT_SUCCESS			0
/**/

/*=== STRUCTURES ===*/
/*DATA*/
typedef struct s_coor
{
	float	x;
	float	y;
	float	z;
}t_coor;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}t_rgb;

/*GLOBAL*/
typedef struct s_amb
{
	char	id;
	float	amb_ratio;
	t_rgb	color;
}t_amb;

typedef struct s_cam
{
	char	id;
	t_coor	view;
	t_coor	vec3;
	int		fov;
}t_cam;

typedef struct s_light
{
	char	id;
	t_coor	point;
	float	bright;
}t_light;

typedef struct t_obj
{
	char			*id;
	t_coor			pos;
	t_coor			vec3;
	t_rgb			color;
	float			diameter;
	struct t_obj	*next;
	struct t_obj	*prev;
}t_obj;

typedef struct s_scene
{
	t_amb	a_light;
	t_light	light;
	t_cam	camera;
	t_obj	*object;
}t_scene;

/*=== FUNCTIONS ===*/
/*INIT*/
bool	init_struct(char *rt_file);
bool	is_dir(char *rt_file);
bool	check_file_format(char *rt_file);
/*PARSING*/
bool	is_valid_line(char *gnl_line);
void	move_index(char *line, int *index, char *id);
bool	already_in_file(char *id, int *a_id, int *c_id, int *l_id);
bool	check_by_id(char *line, char id[3]);
bool	check_amb_line(char *line);
bool	check_cam_line(char *line);
bool	check_light_line(char *line);
bool	check_spher_line(char *line);
bool	check_plane_line(char *line);
bool	check_cylin_line(char *line);
int		check_n_pass_float(char *line);
int		three_follow_value(char *line, int charset);
void	error_by_id(char *id);

#endif