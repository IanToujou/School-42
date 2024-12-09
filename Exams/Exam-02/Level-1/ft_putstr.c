/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:23:37 by ibour             #+#    #+#             */
/*   Updated: 2024/11/25 15:24:02 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <io.h>

void ft_putstr(char *str) {
	int i = 0;
	while (str[i] != '\0') {
		write(1, &str[i], 1);
		i++;
	}
}