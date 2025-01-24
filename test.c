/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:24:31 by ibour             #+#    #+#             */
/*   Updated: 2025/01/24 15:34:20 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

// Function to calculate the highest power of a prime p dividing n!
int legendreFormula(int n, int p) {
	int power = 0;
	int divisor = p;
	while (n / divisor > 0) {
		power += n / divisor;
		divisor *= p;
	}
	return power;
}

int main() {
	int n, p;

	p = 17;
    n = 1;

	// Check if p is a valid prime
	int isPrime = 1;
	if (p < 2) {
		isPrime = 0;
	} else {
		for (int i = 2; i <= sqrt(p); i++) {
			if (p % i == 0) {
				isPrime = 0;
				break;
			}
		}
	}

	while (n <= 100) {
		int result = legendreFormula(n, p);
		if (result == 3) printf("The highest power of %d that divides %d! is: %d\n", p, n, result);
		n++;
	}

	return 0;
}