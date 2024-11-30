/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:12:20 by ibour             #+#    #+#             */
/*   Updated: 2024/11/29 19:44:54 by ibour            ###   ########.fr       */
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

# define WINDOW_NAME "Fractol"
# define WINDOW_SIZE 500
# define MIN_ITERATIONS 256
# define MAX_ITERATIONS 256
# define DEFAULT_COLOR 265

# define SCALE 2
# define FIXED_RADIUS 1
# define MINIMUM_RADIUS 0.5

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define TRICORN 4
# define MANDELBOX 5
# define CELTIC_MANDELBAR 6
# define MANDELBROT_STR "mandelbrot"
# define JULIA_STR "julia"
# define BURNING_SHIP_STR "burning_ship"
# define TRICORN_STR "tricorn"
# define MANDELBOX_STR "mandelbox"
# define CELTIC_MANDELBAR_STR "celtic_mandelbar"

# define UINT u_int32_t

typedef struct s_image
{
	void	*mlx_image;
	char	*address;
	int		pixel_bits;
	int		endian;
	int		line_length;
}	t_image;

typedef struct s_fractal {
	int			type;
	double		zoom;
	UINT		color;
	double		mouse_x;
	double		mouse_y;
	double		offset_x;
	double		offset_y;
	int			iterations;
	bool		julia_lock;
}	t_fractal;

typedef struct s_engine
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_fractal	fractal;
}	t_engine;

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

void	ft_throw_error(int error);

int		ft_init_data(t_engine **engine, char *fractal);

int		ft_init_mlx(t_engine *engine);
void	ft_exit_mlx(t_engine *engine);

#endif
