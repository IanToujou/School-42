/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:11:28 by ibour             #+#    #+#             */
/*   Updated: 2024/12/06 19:15:12 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char reverse_bits(unsigned char octet) {

	int i = 8;
	unsigned char result = 0;

	while (i--) {
		result = (result >> 1) | (octet & 1);
		octet = octet >> 1;
	}
	return result;
}