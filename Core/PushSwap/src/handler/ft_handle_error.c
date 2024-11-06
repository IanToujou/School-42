/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:06:10 by ibour             #+#    #+#             */
/*   Updated: 2024/11/06 09:38:59 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Throws a given error and exits the program if
 * specified.
 */
void	ft_handle_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}
