/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:05:26 by ibour             #+#    #+#             */
/*   Updated: 2024/11/28 18:14:21 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *s1) {
	int len = 0;
	char *str;
	while (s1[len])
		len++;
	str = (char *) malloc(sizeof(str) * (len + 1));
	if (!str)
		return NULL;
	str[len] = '\0';
	len = 0;
	while (s1[len]) {
		str[len] = s1[len];
		len++;
	}
	str[len] = '\0';
	return str;
}
