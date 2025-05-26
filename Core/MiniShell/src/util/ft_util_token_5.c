/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_token_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:13:42 by ibour             #+#    #+#             */
/*   Updated: 2025/05/26 21:47:19 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_bool	ft_util_token_loop_step(char **cmds, t_parse *parse, char *str)
{
	ft_util_quote_status(&parse->quotes, str[parse->i]);
	if (str[parse->i] == '\\' && parse->quotes.two == true
		&& str[parse->i + 1] == '\0')
	{
		parse->i++;
		return (TRUE);
	}
	if ((ft_util_str_strchr("<>| \t", str[parse->i])
			&& !parse->quotes.two && !parse->quotes.one)
		|| str[parse->i + 1] == '\0')
	{
		if (ft_init_token_data(cmds, parse, str) == false)
		{
			ft_util_token_free_cmds(cmds);
			return (FALSE);
		}
		if (parse->flag == true)
			return (FALSE);
	}
	else
		parse->i++;
	return (TRUE);
}

char	**ft_util_token_put(char *str, const int amount)
{
	t_parse	parse;
	char	**cmds;

	parse = ft_init_parse_data();
	cmds = (char **)ft_calloc(amount + 1, sizeof(char *));
	if (cmds == NULL)
		ft_error_throw(ERROR_MALLOC);
	while (str[parse.i])
	{
		if (!ft_util_token_loop_step(cmds, &parse, str))
			return (cmds);
	}
	return (cmds);
}
