/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reflect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:07:57 by ibour             #+#    #+#             */
/*   Updated: 2025/07/15 10:08:04 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vec3	vec_reflect(t_vec3 incident, t_vec3 normal)
{
	return (vec_sub(incident, vec_mul(normal, 2.0 * vec_dot(incident, normal))));
}
