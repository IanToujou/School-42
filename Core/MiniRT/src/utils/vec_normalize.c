/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:13:52 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/19 11:56:42 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vec3 vec_normalize(t_vec3 v)
{
	double length;

	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (length == 0.0)
		return ((t_vec3){0, 0, 0});
	v.x = v.x / length;
	v.y = v.y / length;
	v.z = v.z / length;
	return (v);
}
