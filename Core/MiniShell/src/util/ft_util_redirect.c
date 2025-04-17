/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:15:00 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 01:07:35 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_bool	ft_util_redirect_check(char *str, int *i, char *user)
{
	int		redirect_first;
	int		redirect_second;
	int		j;

	redirect_first = REDIRECT_EMPTY;
	redirect_second = REDIRECT_EMPTY;
	if (str[*i] == '<' || str[*i] == '>')
	{
		redirect_first = redirect_type(str, *i);
		(*i)++;
		if (redirect_first == REDIRECT_OUT_TWO || redirect_first == REDIRECT_IN_TWO)
			(*i)++;
		j = *i;
		while (ft_isblank(str[j]))
			j++;
		if (str[j] == '\0' || str[j] == ';')
			return (error_syntax_token('\n', user));
		redirect_second = redirect_type(str, j);
		if (error_redirect_check(redirect_first,
				redirect_second, user) == false)
			return (FALSE);
	}
	return (TRUE);
}