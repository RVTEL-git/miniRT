/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:48:12 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/06 16:23:50 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include "matrices.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "vector.h"
# include <errno.h>
# include <math.h>
# include <stdlib.h>
# include <sys/stat.h>

/*=== MATHS ===*/
# define M_PI 3.14159265358979323846
# define EPS 1e-6

/*=== COLORS ===*/

# define WHITE_COLOR 0xffffff
# define BLACK_COLOR 0x000000
# define BLUE_COLOR 0x0000ff
# define YELLOW_COLOR 0xffff00
# define GRAY_COLOR 0x969696

/*=== STRUCTURES ===*/
/*DATA*/

typedef struct s_id
{
	bool			a;
	bool			l;
	bool			c;
}					t_id;

typedef struct s_equ
{
	double			a;
	double			b;
	double			c;
}					t_equ;

typedef struct s_ray
{
	t_vec3			dir;
	double			angle;
	t_point			orig;
}					t_ray;

typedef struct s_rgb
{
	double			r;
	double			g;
	double			b;
}					t_rgb;

typedef struct s_hit_data
{
	bool			did_hit;
	double			t;
	struct t_obj	*obj;
	t_vec3			p;
	t_vec3			normal;
}					t_hit_data;

/*GEOMETRY*/

typedef struct s_amb
{
	char			id;
	double			amb_ratio;
	t_rgb			rgb;
}					t_amb;

typedef struct s_cam
{
	char			id;
	t_coor			pos;
	t_coor			look;
	int				fov;
}					t_cam;

typedef struct s_light
{
	char			id;
	t_coor			point;
	double			bright;
}					t_light;

typedef struct t_obj
{
	char			*id;
	t_coor			pos;
	t_coor			v;
	t_rgb			rgb;
	double			diameter;
	double			rad;
	double			height;
	struct t_obj	*next;
	struct t_obj	*prev;
}					t_obj;

typedef struct s_scene
{
	t_amb			a_light;
	t_light			light;
	t_cam			camera;
	t_obj			*object;
	t_coor			tmp;
}					t_scene;

/*MLX*/

typedef struct s_mlx_img
{
	void			*img_ptr;
	char			*img_pixel_ptr;
	int				bits_per_pixel;
	int				endian;
	int				line_len;
}					t_mlx_img;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				height;
	int				width;
	t_mlx_img		img;
}					t_mlx_data;

/*GLOBAAAAAL*/

typedef struct s_global
{
	t_mlx_data		*mlx;
	t_scene			scene;
}					t_global;

/*=== FUNCTIONS ===*/
/*PARSING*/

bool				is_valid(char *gnl_line, char *id, t_id *ids);
void				move_index(char *line, int *index, char *id);
bool				already_in_file(char *id, bool *a_id, bool *c_id,
						bool *l_id);
bool				check_by_id(char id[3], char *line);
bool				check_amb_line(char *line);
bool				check_cam_line(char *line);
bool				check_light_line(char *line);
bool				check_spher_line(char *line);
bool				check_plane_line(char *line);
bool				check_cylin_line(char *line);
int					check_n_pass_double(char *line);
int					three_follow_value(char *line, int charset,
						bool include_double);

/*INIT*/

bool				init_struct(char *rt_file, t_scene *scene);
bool				is_dir(char *rt_file);
bool				check_file_format(char *rt_file);
void				init_by_id(char *id, char *line, t_scene *scene);
bool				check_full(t_scene *scene);
void				pass_double(char *line, int *index);
void				convert_three_value(t_scene *scene, char *line,
						bool use_double);
void				convert_three_int(t_coor *temp, char *line);
void				convert_three_double(t_coor *temp, char *line);
void				assign_three_value(double *fst, double *scn, double *thr,
						t_coor *tmp);
void				pass_three_value(char *line, int *index, bool use_double);
void				init_object(char *line, t_scene *scn, char *id);
bool				check_empty_line(char *line);

/*RENDER*/

t_ray				generate_ray(t_scene *scene, t_mat4 cam_matrix, int x,
						int y, int width, int height);

void				start_render(t_global *minirt);
double				hit_sphere(t_obj *sph, t_ray ray);
double				hit_cylinder(t_obj *cy, t_ray ray);
double				hit_plane(t_obj *pl, t_ray ray);
t_hit_data			*hit_obj(t_ray ray, t_scene *scn, t_hit_data *hit);
int					s_rgb_to_int(int r, int g, int b);

/*MLX*/

bool				init_mlx_struct(t_global *minirt);
void				init_handler(t_global *minirt);
int					close_mlx(t_global *data, int code);
bool	create_mlx_image(t_mlx_data *mlx); // pk bool la
void				my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color);

/*LIST*/

t_obj				*ft_lstlast_obj(t_obj *lst);
void				ft_lstadd_back_obj(t_obj **lst, t_obj *new);
void				ft_lstclear_obj(t_obj *lst);

/*ERROR*/

void				error_by_id(char *id);
void				manage_gnl_error(int fd, char *line, t_scene *scene);
void				manage_extract_error(t_scene *scene, char *id,
						bool message);

/*DEBUG*/
void				print_struct(t_scene *scn);
void	print_obj(t_obj *objects);
void	print_cam(t_cam cam);

#endif
