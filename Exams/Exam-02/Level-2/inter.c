/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:08:41 by ibour             #+#    #+#             */
/*   Updated: 2024/12/04 18:14:12 by ibour            ###   ########.fr       */
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

int main(int argc, char **argv) {

	if (argc == 3) {

		unsigned char found[256] = {0};
		const char *to_find = argv[1];
		const char *text = argv[2];
		int i = 0;
		int j = 0;

		while (text[i]) {
			while (to_find[j]) {
				if (text[i] == to_find[j]) {
					if (!found[to_find[j]]) {
						ft_putchar(to_find[j]);
						found[to_find[j]] = 1;
					}
					break;
				}
				j++;
			}
			i++;
		}

	}

	ft_putchar('\n');
	return (0);

}