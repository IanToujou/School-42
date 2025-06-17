/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:16:25 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/25 15:16:46 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

t_format	parse_format(const char **str)
{
	t_format	format;

	format.iswidthsetup = 0;
	format.flags = 0;
	format.width = 0;
	format.precision = -1;
	format.flags = parse_flags(str);
	format.width = parse_width(str, &format.iswidthsetup);
	format.precision = parse_precision(str, &format.flags);
	return (format);
}
