/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:28:30 by mpoesy            #+#    #+#             */
/*   Updated: 2025/07/15 10:13:25 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"

# include "errortype.h"

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <X11/X.h>

// Window
# define WIDTH 800
# define HEIGHT 600
# define ESC_KEY 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define MOVE_SPEED 5
# define SHININESS 35

typedef struct s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

// ray shot from the camera to each pixel
typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			direction;
}					t_ray;

// color of a pixel
typedef struct s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

// camera needs :
//
// origin point
// a direction of view
// what is up and down for the camera
// how wide can the camera see
typedef struct s_camera
{
	t_vec3			position;
	t_vec3			direction;
	t_vec3			up;
	t_vec3			right;
	t_vec3			forward;
	double			yaw;
	double			pitch;
	double			fov;
}					t_camera;

typedef struct s_ambient
{
	t_color			color;
	double			ratio;
	t_vec3			position; // todo remove
}					t_light;

typedef struct s_image
{
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				line_length;
	int				endian;
}					t_image;

typedef struct s_spotlight
{
	t_vec3			position;
	t_color			color;
	double			diffuse;
	double			specular;
}					t_spotlight;

typedef struct s_cylinder
{
	t_vec3			point;
	t_vec3			axis;
	double			radius;
	double			height;
	t_color			color;
}					t_cylinder;

typedef struct s_cone {
	t_vec3			point;
	t_vec3			axis;
	double			radius;
	double			height;
	t_color			color;
}					t_cone;

typedef struct s_sphere
{
	t_vec3			center;
	double			radius;
	t_color			color;
}					t_sphere;

typedef struct s_plane
{
	t_vec3			point;
	t_vec3			normal;
	t_color			color;
}					t_plane;

// Enum for object types
typedef enum e_obj_type
{
	OBJ_LIGHT,
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	OBJ_CONE,
}					t_obj_type;

// Generic object structure for the linked list
typedef struct s_object
{
	t_obj_type		type;
	void			*data;
	struct s_object	*next;
}					t_object;

// Scene containing the camera, the objects, the light
typedef struct s_scene
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			image;
	t_camera		camera;
	t_light			ambient;
	t_object		*objects;
}					t_scene;

typedef struct s_hit_info
{
	double			t;
	t_vec3			point;
	t_vec3			normal;
	t_color			color;
}					t_hit_info;

// Initialization
void	init_parse(t_scene *scene, const char *file_name);

void	init_mlx(t_scene *scene);
void	init_hook(t_scene *scene);
void	init_data(t_scene *scene);

// Exiting
void	exit_mlx(t_scene *scene);
void	exit_data(t_scene *scene);

// Event
int		event_close(t_scene *scene);
int		event_keypress(int keycode, t_scene *scene);

// Parse
void	parse_ambient(t_scene *scene, char **str);
void	parse_camera(t_scene *scene, char **str);
void	parse_plane(t_scene *scene, char **str);
void	parse_sphere(t_scene *scene, char **str);
void	parse_cylinder(t_scene *scene, char **str);
void	parse_spotlight(t_scene *scene, char **str);
void	parse_cone(t_scene *scene, char **str);

// Math utilities

double	util_num_parse(char *str);
t_vec3	util_vector_parse(char *str);
t_color	util_color_parse(char *str);
void	util_array_free(void **array);
int		util_array_count(void **array);

void	util_camera_update_vec(t_camera *cam);
void	util_camera_update_vec_dir(t_camera *cam);

t_color	util_color_multiply(t_color c1, t_color c2);

t_vec3	vec3(double x, double y, double z);

t_vec3	vec_add(t_vec3 a, t_vec3 b);

t_vec3	vec_sub(t_vec3 a, t_vec3 b);

t_vec3	vec_mul(t_vec3 v, double s);

t_vec3	vec_div(t_vec3 v, double s);

t_vec3	vec_normalize(t_vec3 v);

double	vec_dot(t_vec3 a, t_vec3 b);

t_vec3	vec_cross(t_vec3 a, t_vec3 b);

t_vec3	vec_add_value(t_vec3 a, int value);

double	vec_length(t_vec3 vec);

t_vec3	vec_reflect(t_vec3 incident, t_vec3 normal);
t_vec3	vec_negate(t_vec3 v);

// Scene functions
int		create_scene(char *file, t_scene *scene);

void	render_scene(t_scene *scene);

// Ray & rendering
t_ray	generate_ray(int x, int y, t_camera *cam);

t_color	trace_ray(t_ray *ray, t_scene *scene);

t_color	calculate_lighting(const t_hit_info *hit, t_scene *scene);

int		intersect(t_ray *ray, t_object *obj, t_hit_info *hit);

int		intersect_sphere(t_ray *ray, t_sphere *sphere, t_hit_info *hit);

int		intersect_plane(t_ray *ray, t_plane *plane, t_hit_info *hit);

int		object_cylinder_intersect(t_ray *ray, t_cylinder *cyl, t_hit_info *hit);
int		object_cone_intersect(t_ray *ray, t_cone *cone, t_hit_info *hit);
void	calculate_intersections(t_ray *ray, t_cylinder *cy, double *t_vals);
void	init_hit_info(t_hit_info *hit, t_cylinder *cy);
t_vec3	project_vector(t_vec3 v, t_vec3 axis);
double	get_valid_cylinder_t(double discriminant, t_vec3 *perp_vals);
double	calc_disc(t_vec3 *perp_vals, t_cylinder *cy);
void	calc_perp_comp(t_ray *ray, t_cylinder *cy, t_vec3 *perp_vals);
double	project_length(t_vec3 v, t_vec3 axis);

// Image
void	put_pixel(t_image *img, int x, int y, t_color color);

// Utils
int		error(char *msg);

void	free_scene(t_scene *scene);

t_color	add_color(t_color a, t_color b);

t_color	color_scale(t_color c, double value);

int		add_object_to_scene(t_scene *scene, t_obj_type type, void *data);

#endif
