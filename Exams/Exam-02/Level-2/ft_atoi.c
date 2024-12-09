/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:59:08 by ibour             #+#    #+#             */
/*   Updated: 2024/12/04 18:01:03 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str) {

	int result = 0;
	int sign = 1;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r')
		str++;

	while (*str == '-' || *str == '+') {
		if (*str == '-')
			sign *= -1;
		str++;
	}

	while (*str >= '0' && *str <= '9') {
		result *= 10;
		result += *str - 48;
	}

	return (result * sign);

}
