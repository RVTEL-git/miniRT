/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:48:12 by barmarti          #+#    #+#             */
/*   Updated: 2026/03/25 19:29:21 by egiraud          ###   ########.fr       */
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
# include <stdatomic.h>
# include <stdbool.h>
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

/*=== OTHER ===*/

# define NB_THRDS 24
# define TASKBAR_HEIGHT 69
/* Default number of rays launched per pixel for anti-aliasing*/
# define DEFAULT_AA 67
/* Default rotation angle currently equals Pi/6 */
# define DEFAULT_ROT_ANG 0.52359877559 
# define DEFAULT_SIZE_MOD 0.5

/* Default values for specular coefficient calculation and shineness*/
# define DEFAULT_KS 0.05
# define DEFAULT_SN 100

/*=== MESSAGES ===*/

# define USAGE "Usage :\n\t./miniRT scene/<scene> [-fs] [-aa]\n\t-fs for \
rendering on full screen and -aa to render with antialiasing so it's \
smoother\n\n\tPress h when rendered to show commands and have fun !"
# define COMMANDS "\n\tPress \"n\" and \"p\" to cycle between objects (next \
or previous)\n\tPress \"t\" to go translation mode and \"r\" to go rotation\
mode\n\tPress \"+\" to size up diameter and \"-\" to size down. For cylinders\
\")\" to size up height and \"(\" to size down\n\tPress \"a\" or \"d\" to \
apply selected transformation to axis X, \"w\" or \"s\" for axis Z \
and \"q\" or \"e\" for axis Y.\n\tFinally press space to \
re render!\n"

/*=== STRUCTURES ===*/
/*DATA*/

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

typedef struct s_amb
{
	char			id;
	double			ratio;
	t_rgb			rgb;
}					t_amb;

typedef struct s_cam
{
	t_mat4			trnsf;
	t_coor			pos;
	t_coor			look;
	double			asp_ratio;
	double			fov_scaled;
	double			scrn_height;
	double			scrn_width;
	int				fov;
	char			id;
}					t_cam;

typedef struct s_light
{
	char			id;
	t_coor			point;
	t_rgb			rgb;
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
	bool			antialiasing;
	bool			fullscreen;
}					t_scene;

typedef struct s_thread_data
{
	int				start_y;
	int				end_y;
	t_scene			*scene;
	t_mlx_data		*mlx;
	atomic_int		*counter;
}					t_thread_data;

typedef struct s_id
{
	bool			a;
	bool			l;
	bool			c;
}					t_id;

typedef struct s_ray
{
	t_vec3			dir;
	double			angle;
	t_point			orig;
	t_vec3			compute;
} t_ray,	t_normal;

typedef struct s_hit_data
{
	bool			did_hit;
	double			t;
	struct t_obj	*obj;
	t_ray			*ray;
	t_vec3			p;
	t_normal		normal;
}					t_hit_data;

typedef struct s_specular
{
	double			tens;
	double			ks;
	double			shin;
	t_vec3			p_to_cam;
	t_vec3			p_to_light;
}					t_spec;

typedef struct s_interface
{
	t_obj			*first_obj;
	t_obj			*current_obj;
	int				mode;
}					t_interface;

/*GLOBAAAAAL*/

typedef struct s_global
{
	t_mlx_data		*mlx;
	t_scene			scene;
	t_interface		interface;
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

void				render(t_scene *scene, t_mlx_data *mlx);
int					get_final_rgb(t_thread_data *args, int x, int y);
void				init_thrd_args(int i, t_scene *scene, t_mlx_data *mlx,
						t_thread_data *args);
void				start_render(t_global *minirt);
t_cam				*init_camera(t_cam *cam, int width, int height);
t_ray				generate_ray(t_cam *cam, double x, double y, bool fixed);
void				hit_obj(t_ray ray, t_scene *scn, t_hit_data *hit);
double				hit_sphere(t_obj *sph, t_ray ray);
double				hit_cylinder(t_obj *cy, t_ray ray);
double				hit_plane(t_obj *pl, t_ray ray);
t_normal			get_normal(t_hit_data *hit, t_obj *obj);
t_normal			get_normal(t_hit_data *hit, t_obj *obj);
t_rgb				get_rgb(t_hit_data *hit, t_scene *scene);
int					s_rgb_to_int(t_vec3 rgb);
int					sum_rgb(t_rgb *colors, size_t len);
t_rgb				init_ambient(t_hit_data *hit, t_scene *scene);
t_rgb				init_diffuse(t_hit_data *hit, t_scene *scene);
t_rgb				init_specular(t_hit_data *hit, t_scene *scene);

/*CARMERA*/

t_vec3				mat4_apply_translation(t_mat4 m, t_vec3 v);
t_vec3				mat4_apply(t_mat4 m, t_vec3 p);
t_mat4				mat4_look_at(t_vec3 orig, t_vec3 dir);
double				randfrom(double min, double max);

/*COLOR*/

t_vec3				vec3_clamp(t_vec3 to_clamp, double min, double max);
t_rgb				get_final(t_rgb diffuse, t_rgb specular, t_rgb ambient);

/*MLX*/

bool				init_mlx_struct(t_global *minirt);
void				init_handler(t_global *minirt);
int					close_mlx(t_global *data, int code);
bool				create_mlx_image(t_mlx_data *mlx);
void				my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color);

/* TRANSFORM */

void				change_object(t_global *data, int keysym);
void				apply_transformation(t_global *data, int keysym);
void				translate_object(t_global *global, int keysym);
void				rotate_object(t_global *global, int keysym);
void				change_size(t_global *data, int keysym);
void				print_status(t_global *data);

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
void				print_obj(t_obj *objects);
void				print_cam(t_cam cam);
int					check_flags_debug(char **av);

#endif
