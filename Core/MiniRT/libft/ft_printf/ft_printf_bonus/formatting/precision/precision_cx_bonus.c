/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:33:59 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/28 12:35:55 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf_bonus.h"

char	*precision_cx(char *str, t_format *format)
{
	char	*result;
	size_t	i;

	result = precision_x(str, format);
	if (!result)
		return (NULL);
	i = 0;
	while (result[i])
	{
		result[i] = ft_toupper(result[i]);
		i++;
	}
	return (result);
}
