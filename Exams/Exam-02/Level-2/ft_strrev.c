/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:21:11 by ibour             #+#    #+#             */
/*   Updated: 2024/11/28 18:25:51 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char *ft_strrev(char *str) {
	if (!str)
		return (NULL);
	int len = 0;
	int i = 0;
	char c;
	while (str(len))
		len++;
	while (i < len / 2) {
		c = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = c;
		i++;
	}
	return (str);
}
