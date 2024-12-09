/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:44:34 by ibour             #+#    #+#             */
/*   Updated: 2024/12/07 16:01:55 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <io.h>

void ft_putchar(const char c) {
	write(1, &c, 1);
}

void ft_putnbr(const int num) {

	if (num < 0) {
		ft_putchar('-');
		ft_putnbr(-num);
		return;
	}

	if (num >= 10)
		ft_putnbr(num / 10);

	ft_putchar(num % 10 + '0');

}

int ft_atoi(const char *str) {

	int result = 0;

	while (*str) {
		result *= 10;
		result += *str - '0';
	}

	return result;

}

int is_prime(int num) {

	if (num <= 1)
		return (0);

	int i = 2;

	while (i * i <= num) {
		if (num % i == 0)
			return (0);
		i++;
	}

	return (1);

}

int main(int argc, char **argv) {

	if (argc == 2) {

		int result = 0;
		int num = ft_atoi(argv[1]);

		while (num > 0) {
			if (is_prime(num))
				result += num;
			num--;
		}

		ft_putnbr(result);

	} else ft_putchar('0');

	ft_putchar('\n');
	return (0);

}