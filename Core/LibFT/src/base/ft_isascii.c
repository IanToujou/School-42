/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_isascii.c >                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Checks whether a character is in the default ASCII table.
 * It does this by comparing the ASCII values.
 *
 * @param c The character to check.
 * @return 0 if the condition is false, and 1 on true.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
