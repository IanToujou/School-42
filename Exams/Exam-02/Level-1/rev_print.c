/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:32:43 by ibour             #+#    #+#             */
/*   Updated: 2024/11/25 15:36:51 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <io.h>

char	*rev_print(char *str) {
	int length = 0;
	while (str[length] != '\0')
		length++;
	while (length > 0) {
		write(1, &str[length-1], 1);
		length--;
	}
	return (str);
}