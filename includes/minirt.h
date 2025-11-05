/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:48:12 by barmarti          #+#    #+#             */
/*   Updated: 2025/11/05 17:46:57 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <errno.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"

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
	float	r;
	float	g;
	float	b;
}t_rgb;

/*GLOBAL*/
typedef struct s_amb
{
	char	id;
	float	amb_ratio;
	t_rgb	rgb;
}t_amb;

typedef struct s_cam
{
	char	id;
	t_coor	view;
	t_coor	v;
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
	t_coor			v;
	t_rgb			rgb;
	float			diameter;
	float			height;
	struct t_obj	*next;
	struct t_obj	*prev;
}t_obj;

typedef struct s_scene
{
	t_amb	a_light;
	t_light	light;
	t_cam	camera;
	t_obj	*object;
	t_coor	tmp;
}t_scene;

/*=== FUNCTIONS ===*/
/*INIT*/

bool	init_struct(char *rt_file);
bool	is_dir(char *rt_file);
bool	check_file_format(char *rt_file);
void	init_by_id(char *id, char *line, t_scene *scene);
bool	check_full(t_scene *scene);
void	pass_float(char *line, int *index);
void	convert_three_value(t_scene *scene, char *line, bool use_float);
void	convert_three_int(t_coor *temp, char *line);
void	convert_three_float(t_coor *temp, char *line);
void	assign_three_value(float *fst, float *scn, float *thr, t_coor *tmp);
void	pass_three_value(char *line, int *index, bool use_float);
void	init_object(char *line, t_scene *scn, char *id);

/*PARSING*/

bool	is_valid(char *gnl_line, char *id);
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
int		three_follow_value(char *line, int charset, bool include_float);

/*LIST*/

t_obj	*ft_lstlast_obj(t_obj *lst);
void	ft_lstadd_back_obj(t_obj **lst, t_obj *new);

/*ERROR*/

void	error_by_id(char *id);
void	manage_gnl_error(int fd, char *line, t_scene *scene);
void	manage_exctract_error(t_scene *scene, char *id, bool message);

/*DEBUG*/
void print_struct(t_scene *scn);

#endif