/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:43:40 by ibour             #+#    #+#             */
/*   Updated: 2024/11/28 17:45:57 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <io.h>

int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 2) {
		while (argv[1][i]) {
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] = ('a' + 'z') - argv[1][i];
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = ('A' + 'Z') - argv[1][i];
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
