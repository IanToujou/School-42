/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:27:23 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/20 13:31:47 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void put_pixel(t_image *image, int x, int y, t_color color)
{
	char *dst;
	int pixel_color;

	// int		r;
	// int		g;
	// int		b;
	// r = (int)(fmin(color.r, 1.0) * 255.0);
	// g = (int)(fmin(color.g, 1.0) * 255.0);
	// b = (int)(fmin(color.b, 1.0) * 255.0);
	pixel_color = (color.r << 16) | (color.g << 8) | color.b;
	dst = image->data + (y * image->line_length + x * (image->bpp / 8));
	*(unsigned int *) dst = pixel_color;
}

void render_scene(t_scene *scene)
{
	t_ray ray;
	t_color color;
	int y;
	int x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = generate_ray(x, y, &scene->camera);
			color = trace_ray(&ray, scene);
			// printf("Pixel (%d,%d): Ray origin=(%.2f,%.2f,%.2f) dir=(%.2f,%.2f,%.2f),
			//	Color=(R:%d G:%d B:%d)\n",
			// x, y,
			// ray.origin.x, ray.origin.y, ray.origin.z,
			// ray.direction.x, ray.direction.y, ray.direction.z,
			// color.r, color.g, color.b);
			put_pixel(&scene->image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(scene->mlx_ptr, scene->win_ptr,
	                        scene->image.img_ptr, 0, 0);
}
