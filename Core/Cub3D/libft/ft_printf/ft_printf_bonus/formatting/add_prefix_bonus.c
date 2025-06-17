/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prefix_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:53:17 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/18 16:21:05 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*add_prefix(char *str, char specifier)
{
	char	*final_str;
	char	*prefix;
	int		len_str;
	int		len_prefix;

	if (!(specifier == 'p'))
		return (str);
	else
		prefix = "0x";
	if (!str || !prefix)
		return (NULL);
	len_str = ft_strlen(str);
	len_prefix = ft_strlen(prefix);
	final_str = (char *)malloc(len_str + len_prefix + 1);
	if (!final_str)
		return (NULL);
	ft_strlcpy(final_str, prefix, len_prefix + 1);
	ft_strlcpy(final_str + len_prefix, str, len_str + 1);
	return (final_str);
}
