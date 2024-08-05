/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:15:07 by ibour             #+#    #+#             */
/*   Updated: 2024/07/17 14:15:07 by ibour            ###   ########.fr       */
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
