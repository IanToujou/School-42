/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:53:26 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 17:11:00 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_bool	ft_init_token_cmd(char **cmds, t_parse *parse, const char *str)
{
	if (str[parse->i] != '|' && str[parse->i + 1] == '\0')
		(parse->i)++;
	cmds[parse->index_token] = ft_substr(str, parse->begin_str,
			parse->i - parse->begin_str);
	if (cmds[parse->index_token] == NULL)
		return (FALSE);
	if (ft_util_str_strchr("<>|", str[parse->i]) == FALSE
		&& str[parse->i] != '\0')
	{
		(parse->i)++;
		while (ft_isblank(str[parse->i]))
			(parse->i)++;
		parse->begin_str = parse->i;
	}
	(parse->index_token)++;
	return (TRUE);
}

static t_bool	ft_init_token_sym_red(char **cmds,
		t_parse *parse, const char *str)
{
	if (ft_util_str_strchr("<>", str[parse->i + 1]))
	{
		if (str[parse->i + 1] == '>')
			cmds[parse->index_token] = ft_strdup(">>");
		else
			cmds[parse->index_token] = ft_strdup("<<");
		(parse->i)++;
	}
	else if (str[parse->i] == '>')
		cmds[parse->index_token] = ft_strdup(">");
	else if (str[parse->i] == '<')
		cmds[parse->index_token] = ft_strdup("<");
	if (cmds[parse->index_token] == NULL)
		return (FALSE);
	(parse->i)++;
	while (ft_isblank(str[parse->i]))
		(parse->i)++;
	parse->begin_str = parse->i;
	(parse->index_token)++;
	return (TRUE);
}

static t_bool	ft_init_token_sym(char **cmds, t_parse *parse, char *str)
{
	if (ft_util_str_strchr("<>", str[parse->i]))
	{
		if (ft_init_token_sym_red(cmds, parse, str) == false)
			return (FALSE);
	}
	else
	{
		cmds[parse->index_token] = ft_strdup("|");
		if (cmds[parse->index_token] == NULL)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	ft_init_token_data(char **cmds, t_parse *parse, char *str)
{
	if (str[parse->i] == '|' || str[parse->i + 1] == '\0')
		parse->flag = TRUE;
	if (ft_util_str_strchr("<>|", str[parse->i]))
	{
		if (parse->i != 0)
		{
			if (ft_isblank(str[parse->i - 1]) == FALSE)
			{
				if (ft_init_token_cmd(cmds, parse, str) == FALSE)
					return (FALSE);
			}
		}
		if (ft_init_token_sym(cmds, parse, str) == FALSE)
			return (FALSE);
	}
	else
	{
		if (ft_init_token_cmd(cmds, parse, str) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}
