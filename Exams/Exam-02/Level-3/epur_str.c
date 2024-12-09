/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:07:45 by ibour             #+#    #+#             */
/*   Updated: 2024/12/07 16:28:42 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv) {

	if (argc == 2) {

		int i = 0;
		int flag = 0;

		while (argv[1][i] != ' ' || argv[1][i] != '\t')
			i += 1;

		while (argv[1][i]) {

			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				flag = 1;
			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
			{
				if (flag)
					write(1, " ", 1);
				flag = 0;
				write(1, &argv[1][i], 1);
			}
			i += 1;

		}

	}

	write(1, "\n", 1);

}
