/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:34:11 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 04:47:31 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_util_controls_zoom(int key, t_data *data)
{
	if (key == KEY_NUMPAD_PLUS ||
		key == KEY_PLUS ||
		key == MOUSE_SCROLL_UP)
		data->camera->zoom++;
	else if (key == KEY_NUMPAD_MINUS ||
		key == KEY_MINUS ||
		key == MOUSE_SCROLL_DOWN)
		data->camera->zoom--;
	if (data->camera->zoom < 1)
		data->camera->zoom = 1;
	ft_graphics_draw(data->map, data);
}

void	ft_util_controls_move(int key, t_data *data)
{
	if (key == KEY_LEFT)
		data->camera->x_offset -= 10;
	else if (key == KEY_RIGHT)
		data->camera->x_offset += 10;
	else if (key == KEY_UP)
		data->camera->y_offset -= 10;
	else
		data->camera->y_offset += 10;
	ft_graphics_draw(data->map, data);
}

void	ft_util_controls_rotate(int key, t_data *data)
{
	if (key == KEY_NUMPAD_TWO || key == KEY_TWO)
		data->camera->alpha += 0.05;
	else if (key == KEY_NUMPAD_EIGHT || key == KEY_EIGHT)
		data->camera->alpha -= 0.05;
	else if (key == KEY_NUMPAD_FOUR || key == KEY_FOUR)
		data->camera->beta -= 0.05;
	else if (key == KEY_NUMPAD_SIX || key == KEY_SIX)
		data->camera->beta += 0.05;
	else if (key == KEY_NUMPAD_ONE || key == KEY_ONE
		|| key == KEY_NUMPAD_THREE || key == KEY_THREE)
		data->camera->gamma += 0.05;
	else if (key == KEY_NUMPAD_SEVEN || key == KEY_SEVEN
		|| key == KEY_NUMPAD_NINE || key == KEY_NINE)
		data->camera->gamma -= 0.05;
	ft_graphics_draw(data->map, data);
}

void	ft_util_controls_flatten(int key, t_data *data)
{
	if (key == KEY_C)
		data->camera->z_divisor -= 0.1;
	else if (key == KEY_V)
		data->camera->z_divisor += 0.1;
	if (data->camera->z_divisor < 0.1)
		data->camera->z_divisor = 0.1;
	else if (data->camera->z_divisor > 10)
		data->camera->z_divisor = 10;
	ft_graphics_draw(data->map, data);
}

void	ft_util_controls_project(int key, t_data *data)
{
	data->camera->alpha = 0;
	data->camera->beta = 0;
	data->camera->gamma = 0;
	if (key == KEY_I)
		data->camera->projection = ISOMETRIC;
	else if (key == KEY_P)
		data->camera->projection = PARALLEL;
	ft_graphics_draw(data->map, data);
}
