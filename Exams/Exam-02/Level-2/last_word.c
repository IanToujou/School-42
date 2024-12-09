/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:32:21 by ibour             #+#    #+#             */
/*   Updated: 2024/12/06 16:53:12 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <io.h>

void ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_putstr(const char *str) {
	while (*str)
		ft_putchar(*str++);
}

int main(int argc, char **argv) {

	const char *str = argv[1];

	if (argc == 2) {
		int j = 0;
		int i = 0;

		while (str[i]) {
			if (str[i] == ' ' && str[i+1] >= 33 && str[i+1] <= 126) {
				j = i + 1;
			}
			i++;
		}

		while (str[j] >= 33 && str[j] <= 126)
			ft_putchar(str[j++]);

	}

	ft_putchar('\n');

}
