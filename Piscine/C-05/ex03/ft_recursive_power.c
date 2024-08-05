/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:38:05 by ibour             #+#    #+#             */
/*   Updated: 2024/07/17 13:38:06 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power_recursive(int nb, int power, int result)
{
	if (power > 0)
	{
		power--;
		return (ft_recursive_power_recursive(nb, power, result *= nb));
	}
	return (result);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	return (ft_recursive_power_recursive(nb, power, 1));
}
