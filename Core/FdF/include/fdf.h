/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:33:19 by ibour             #+#    #+#             */
/*   Updated: 2025/07/17 09:51:16 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define WIDTH 1280
# define HEIGHT 720
# define ESC_KEY 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include <X11/X.h>
# include "errortype.h"

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

void	init_data(t_data *data);
void	init_parse(t_data *data, char *file);
void	init_mlx(t_data *data);
void	init_hook(t_data *data);

void	exit_data(t_data *data);
void	exit_mlx(t_data *data);

int		event_close(t_data *data);
int		event_keypress(int keycode, t_data *data);

void	gfx_render(t_data *data);

#endif