/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_div.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:03:28 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/19 11:56:49 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vec3	vec_div(t_vec3 v, double s)
{
	t_vec3	result;

	if (s == 0)
	{
		error("division by 0 in vec_div\n");
		result.x = 0;
		result.y = 0;
		result.z = 0;
		return (result);
	}
	result.x = v.x / s;
	result.y = v.y / s;
	result.z = v.z / s;
	return (result);
}
