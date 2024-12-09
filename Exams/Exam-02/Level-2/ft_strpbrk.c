/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:02:02 by ibour             #+#    #+#             */
/*   Updated: 2024/12/04 18:06:11 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char *ft_strpbrk(const char *str, const char *charset) {

	int i = 0;

	if (str == NULL || charset == NULL)
		return (0);

	while (*str) {
		while (charset[i]) {
			if (*str == charset[i])
				return (char*) str;
			i++;
		}
		str++;
	}

	return (NULL);

}
