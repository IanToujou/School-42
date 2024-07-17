/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:15:24 by ibour             #+#    #+#             */
/*   Updated: 2024/07/17 14:15:25 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	result;

	result = 1;
	while (result * result < nb && result < nb / 2)
		result++;
	if (result * result == nb)
		return (result);
	return (0);
}

int	ft_is_prime(int nb)
{
	int	index;
	int	sqrt;

	if (nb < 2)
		return (0);
	if (nb <= 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	index = 2;
	sqrt = ft_sqrt(nb);
	while ((index <= sqrt) && (nb % index != 0))
		index++;
	return (index > sqrt);
}
