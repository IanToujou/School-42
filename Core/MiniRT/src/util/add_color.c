/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:12:06 by mpoesy            #+#    #+#             */
/*   Updated: 2025/07/07 17:59:57 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_color	add_color(t_color a, t_color b)
{
	t_color	result;

	result.r = fmin(a.r + b.r, 255);
	result.g = fmin(a.g + b.g, 255);
	result.b = fmin(a.b + b.b, 255);
	return (result);
}

t_color	util_color_multiply(t_color c1, t_color c2)
{
	t_color	result;

	result.r = (c1.r * c2.r) / 255;
	result.g = (c1.g * c2.g) / 255;
	result.b = (c1.b * c2.b) / 255;
	return (result);
}
