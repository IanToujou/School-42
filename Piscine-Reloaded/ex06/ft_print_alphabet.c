/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:03:12 by ibour             #+#    #+#             */
/*   Updated: 2024/07/10 12:22:30 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	letter;

	letter = 'a';
	while (letter <= 'z')
	{
		ft_putchar(letter);
		letter++;
	}
}
