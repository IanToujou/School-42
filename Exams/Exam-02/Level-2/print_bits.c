/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:13:15 by ibour             #+#    #+#             */
/*   Updated: 2024/12/06 17:16:06 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <io.h>

void print_bits(unsigned char octet) {

	int i = 8;
	unsigned char bit;

	while (i--) {
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}

}
