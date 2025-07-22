/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:48:01 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 09:47:14 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vec3	util_vector_parse(char *str)
{
	t_vec3	result;
	char	**values;
	int		i;

	if (!str)
		error_throw(ERROR_PARSE_VECTOR);
	values = ft_split(str, ',');
	if (!values)
		error_throw(ERROR_MALLOC);
	i = 0;
	while (values[i])
		i++;
	if (i != 3)
	{
		util_array_free((void **) values);
		error_throw(ERROR_PARSE_VECTOR);
	}
	result.x = util_num_parse(values[0]);
	result.y = util_num_parse(values[1]);
	result.z = util_num_parse(values[2]);
	util_array_free((void **) values);
	return (result);
}
