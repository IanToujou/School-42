/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:08:55 by ibour             #+#    #+#             */
/*   Updated: 2024/12/07 15:41:54 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <io.h>

void ft_putchar(const char c) {
	write(1, &c, 1);
}

void ft_putstr(const char *str) {
	while (*str)
		ft_putchar(*str++);
}

int main(const int argc, char **argv) {

	if (argc == 3) {
		int i = 0, j = 0;
		const char *to_write = argv[1];
		const char *str = argv[2];

		while (str[j]) {
			if (to_write[i] == str[j])
				i++;
			j++;
		}

		if (to_write[i] == '\0')
			ft_putstr(to_write);

	}

	write(1, "\n", 1);
	return (0);

}
