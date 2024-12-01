/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:29:25 by ibour             #+#    #+#             */
/*   Updated: 2024/12/01 14:59:21 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	ft_gfx_mandelbrot(const t_fractal *fractal, t_complex *c)
{
	double		r_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.r = 0;
	z.i = 0;
	while ((z.r * z.r + z.i * z.i) < 4 && ++i < fractal->iterations)
	{
		r_temp = z.r * z.r - z.i * z.i + c->r;
		z.i = 2 * z.r * z.i + c->i;
		z.r = r_temp;
	}
	return (i);
}

int	ft_gfx_julia(const t_fractal *fractal, const t_complex *c, const int x, const int y)
{
	double		r_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.r = (x / fractal->zoom) + fractal->offset_x;
	z.i = (y / fractal->zoom) + fractal->offset_y;
	while ((z.r * z.r + z.i * z.i) < 4 && ++i < fractal->iterations)
	{
		r_temp = z.r * z.r - z.i * z.i + c->r;
		z.i = 2 * z.r * z.i + c->i;
		z.r = r_temp;
	}
	return (i);
}

int	ft_gfx_burningship(t_fractal *fractal, t_complex *c)
{
	double		re_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.r = 0;
	z.i = 0;
	while ((z.r * z.r + z.i * z.i) < 4 && ++i < fractal->iterations)
	{
		re_temp = z.r * z.r - z.i * z.i + c->r;
		z.i = fabs(2 * z.r * z.i) + c->i;
		z.r = fabs(re_temp);
	}
	return (i);
}

int	ft_gfx_tricorn(t_fractal *fractal, t_complex *c)
{
	double		r_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.r = 0;
	z.i = 0;
	while ((z.r * z.r + z.i * z.i) < 4 && ++i < fractal->iterations)
	{
		r_temp = z.r * z.r - z.i * z.i + c->r;
		z.i = -2 * z.r * z.i + c->i;
		z.r = r_temp;
	}
	return (i);
}

int	ft_gfx_celtic_mandelbar(t_fractal *fractal, t_complex *c)
{
	double		r_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.r = 0;
	z.i = 0;
	while ((z.r * z.r + z.i * z.i) < 4 && ++i < fractal->iterations)
	{
		r_temp = z.r * z.r - z.i * z.i;
		z.i = -2 * z.r * z.i + c->i;
		if (r_temp < 0)
			r_temp *= -1;
		z.r = r_temp + c->r;
	}
	return (i);
}
