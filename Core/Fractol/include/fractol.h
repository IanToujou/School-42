/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:12:20 by ibour             #+#    #+#             */
/*   Updated: 2024/11/26 21:19:15 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "errortype.h"

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>

# define WINDOW_NAME "BLUE METH DRUG CARTEL SIMULATOR"
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

typedef struct	s_engine {
	void	*mlx;
	void	*window;
	int		window_height;
	int		window_width;
}	t_engine;

void	ft_throw_error(int error);

int		ft_init_mlx(t_engine *engine);
void	ft_exit_mlx(t_engine *engine);

#endif
