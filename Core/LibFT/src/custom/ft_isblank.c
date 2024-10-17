/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_isblank.c >                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Checks whether a character is a blank character.
 * It includes the space and horizontal tab character.
 *
 * @param c The character to check.
 * @return 0 if the condition is false, and 1 on true.
 */
int	ft_isblank(int c)
{
	return (c == ' ' || c == '\t');
}
