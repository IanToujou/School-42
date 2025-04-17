/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:11:16 by ibour             #+#    #+#             */
/*   Updated: 2025/04/17 20:12:07 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_bool	ft_util_quote_set(t_quotes *quotes, const char c)
{
	if (c == '\'' && quotes->one == true)
		quotes->one = false;
	else if (c == '\'' && quotes->two == false)
		quotes->one = true;
	else if (c == '"' && quotes->two == true)
		quotes->two = false;
	else if (c == '"' && quotes->one == false)
		quotes->two = true;
	else
		return (false);
	return (true);
}

t_bool	ft_util_quote_is_outside(const t_quotes *quotes)
{
	return (quotes->two == false && quotes->one == false);
}
