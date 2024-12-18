/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:45:40 by ibour             #+#    #+#             */
/*   Updated: 2024/12/18 11:45:48 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_util_algo_line(const t_image *image, const t_point2d a, const t_point2d b)
{
	int			error[];
	t_point2d	p;

	p.x = a.x;
	p.y = a.y;
	error[0] = abs(b.x - a.x) + abs(b.y - a.y);
	while(p.x != b.x && p.y != b.y)
	{
		if ((uint32_t)p.x < image->width && (uint32_t)p.y < image->height)
			ft_put_pixel(image, p.x, p.y, 0);
		error[1] = 2 * error[0];
		if (error[1] > -abs(b.y - a.y))
		{
			error[0] -= abs(b.y - a.y);
			p.x += (a.x < b.x);
			p.x -= (b.x < a.x);
		}
		if (error[1] < abs(b.x - a.x))
		{
			error[0] += abs(b.x - a.x);
			p.y += (a.y < b.y);
			p.y -= (b.y < a.y);
		}
	}
}
