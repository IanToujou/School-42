/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:30:50 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/16 13:21:39 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// 3-dim vector that define a position in space
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
	t_vec3			origin;
	t_vec3			direction;
	t_vec3			up;
	t_vec3			right;
	t_vec3			forward;
	double			yaw;
	double			pitch;
	double			fov;
}					t_camera;

// Struct that defines the properties of light
typedef struct s_light
{
	t_vec3			position;
	t_color			color;
	double			intensity;
}					t_light;

// Image for minilibx
typedef struct s_image
{
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				line_length;
	int				endian;
}					t_image;

typedef struct s_cylinder
{
	t_vec3			point;
	t_vec3			axis;
	double			radius;
	double			height;
	t_color			color;
}					t_cylinder;

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
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
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
	t_light			light;
	t_object		*objects;
}					t_scene;

typedef struct s_hit_info
{
	double			t;
	t_vec3			point;
	t_vec3			normal;
	t_color			color;
}					t_hit_info;

#endif
