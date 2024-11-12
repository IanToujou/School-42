/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:56:12 by ibour             #+#    #+#             */
/*   Updated: 2024/11/12 09:37:13 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "errortype.h"

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WINDOW_NAME "BLUE METH DRUG CARTEL SIMULATOR"
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define KEY_ESCAPE 27
# define A 97
# define D 100
# define S 115
# define W 119

typedef struct s_gamedata {
	void	*mlx;
	void	*window;
}	t_gamedata;

void	ft_throw_error(int error);

int		ft_init_mlx(t_gamedata **gamedata);
int		ft_init_hooks(const t_gamedata *gamedata);

int		ft_event_keypress(int keycode, t_gamedata *gamedata);
int		ft_event_close(t_gamedata *gamedata);

#endif