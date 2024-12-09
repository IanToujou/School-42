/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:53:35 by ibour             #+#    #+#             */
/*   Updated: 2024/12/06 21:08:14 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <io.h>

void ft_putchar(char c) {
	write(1, &c, 1);
}

int main(int argc, char **argv) {

	if (argc == 3) {

		int i = 0;
		char seen[256] = {0};

		while (argv[1][i]) {
			if (seen[argv[1][i]] == 0) {
				ft_putchar(argv[1][i]);
				seen[argv[1][i]] = 1;
			}
			i++;
		}

		i = 0;
		while (argv[2][i]) {
			if (seen[argv[2][i]] == 0) {
				ft_putchar(argv[2][i]);
				seen[argv[2][i]] = 1;
			}
			i++;
		}

	}

	ft_putchar('\n');

}