/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:08:41 by ibour             #+#    #+#             */
/*   Updated: 2025/04/17 20:09:10 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_quotes	ft_init_quote(void)
{
	t_quotes	quotes;

	quotes.two = false;
	quotes.one = false;
	return (quotes);
}
