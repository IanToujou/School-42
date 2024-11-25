/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:18:11 by ibour             #+#    #+#             */
/*   Updated: 2024/11/25 15:23:06 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <io.h>

void putchar(char c) {
	write(1, &c, 1);
}

void putnbr(int nb) {
	if (nb < 10) {
		putchar(nb + '0');
		return;
	}
		putnbr(nb / 10);
	putnbr(nb % 10);
}

int main(void) {
	int i = 1;
	while (i <= 100) {
		if (i % 3 == 0 && i % 5 == 0) write(1, "fizzbuzz", 8);
		else if (i % 3 == 0) write(1, "fizz", 4);
		else if (i % 5 == 0) write(1, "buzz", 4);
		else putnbr(i);
		write(1, "\n", 1);
		i++;
	}
}