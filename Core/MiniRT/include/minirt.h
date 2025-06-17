/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:28:30 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/17 10:48:32 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "structs.h" // structs here
# include <fcntl.h>   // open/read
# include <math.h>
# include <stdio.h> // debugging/printf
# include <stdlib.h>
# include <unistd.h>

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
# define MOVE_SPEED 0.4

// Math utilities
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

// Scene functions
int		create_scene(char *file, t_scene *scene);
void	render_scene(t_scene *scene);

// Ray & rendering
t_ray	generate_ray(int x, int y, t_camera *cam);
t_color	trace_ray(t_ray *ray, t_scene *scene);
t_color	calculate_lighting(t_hit_info *hit, t_scene *scene);
int		intersect(t_ray *ray, t_object *obj, t_hit_info *hit);
int		intersect_sphere(t_ray *ray, t_sphere *sphere, t_hit_info *hit);
int		intersect_plane(t_ray *ray, t_plane *plane, t_hit_info *hit);
int		intersect_cylinder(t_ray *ray, t_cylinder *cyl, t_hit_info *hit);

// Image
void	put_pixel(t_image *img, int x, int y, t_color color);

// Utils
int		error(char *msg);
void	free_scene(t_scene *scene);
t_color	add_color(t_color a, t_color b);
t_color	color_scale(t_color c, double value);

#endif
