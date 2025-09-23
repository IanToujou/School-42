/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render_ui.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:45:36 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 10:02:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	gfx_render_ui_menu(const t_data *data, int *y)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, *y += 30, MENU_COLOR
			, "[W/A/S/D] Move");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, *y += 15, MENU_COLOR
			, "[Up/Down] Altitude Ratio");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, *y += 15, MENU_COLOR
			, "[Numpad] Rotate");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, *y += 15, MENU_COLOR
			, "[+/-] Zoom");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, *y += 30, MENU_COLOR
			, "[Space] Reset");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, *y += 15, MENU_COLOR
			, "[Escape] Close");
}

static void	gfx_render_ui_title(const t_data *data, int *y)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, *y += 20, MENU_COLOR
			, "FdF Viewer");
}

void	gfx_render_ui(const t_data *data)
{
	int	y;

	y = 20;
	mlx_set_font(data->mlx_ptr, data->win_ptr, "-misc-fixed-bold-r-normal--14-130-75-75-c-70-iso8859-1");
	gfx_render_ui_title(data, &y);
	mlx_set_font(data->mlx_ptr, data->win_ptr, "-misc-fixed-medium-r-normal--14-130-75-75-c-70-iso8859-1");
	gfx_render_ui_menu(data, &y);
}