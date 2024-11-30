/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:55:01 by ibour             #+#    #+#             */
/*   Updated: 2024/11/28 18:04:57 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t strcspn(const char *s1, const char *s2) {
	size_t i = 0;
	size_t j = 0;
	while (s1[i]) {
		while (s2[j]) {
			if (s1[i] == s2[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
