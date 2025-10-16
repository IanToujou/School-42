/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:30:30 by ibour             #+#    #+#             */
/*   Updated: 2025/10/15 20:33:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main() {

	int x = 0;
	int y = 0;

	printf("start\n");

	while (x < 3) {

		while (y < 3) {

			if (y == 1) {
				printf("Continue called\n");
				y++;
				continue;
			}
			printf("end of inner loop\n");
			y++;
		}

		printf("end of outer loop\n");
		x++;

	}

	printf("end of program\n");

}
