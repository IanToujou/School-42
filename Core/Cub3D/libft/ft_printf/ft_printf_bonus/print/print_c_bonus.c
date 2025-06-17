/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:36 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/25 13:44:22 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	print_c(int c, t_format *format)
{
	char	*str;
	int		num_char;
	char	*formatted_str;

	if (c == 0)
		return (handle_zero(format));
	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (0);
	str[0] = c;
	str[1] = '\0';
	formatted_str = apply_flags(str, format, 'c');
	if (!formatted_str)
		return (0);
	num_char = write(1, formatted_str, ft_strlen(formatted_str));
	free(formatted_str);
	return (num_char);
}
