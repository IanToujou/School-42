/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_token_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:21:17 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 13:15:35 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_bool	ft_util_token_free_process(char *cmd, char **cmds)
{
	int		i;

	i = -1;
	if (cmd != NULL)
		free(cmd);
	if (cmds != NULL)
	{
		while (cmds[++i])
			free(cmds[i]);
		free(cmds);
	}
	return (FALSE);
}

static char	**ft_util_token_free(char **cmds)
{
	int			i;

	i = -1;
	if (cmds)
	{
		while (cmds[++i])
			free(cmds[i]);
		free(cmds);
		cmds = NULL;
	}
	return (cmds);
}

static char	**ft_util_token_put(char *str, const int amount)
{
	t_parse		parse;
	char		**cmds;

	parse = ft_init_parse_data();
	cmds = (char **) ft_calloc(amount + 1, sizeof(char *));
	if (cmds == NULL)
		ft_error_throw(ERROR_MALLOC);
	while (str[parse.i])
	{
		ft_util_quote_status(&parse.quotes, str[parse.i]);
		if (str[parse.i] == '\\' && parse.quotes.two == true
			&& str[parse.i + 1] == '\0')
			parse.i++;
		if ((ft_util_str_strchr("<>| \t", str[parse.i]) && parse.quotes.two == false
				&& parse.quotes.one == false) || str[parse.i + 1] == '\0')
		{
			if (ft_init_token_data(cmds, &parse, str) == false)
				return (ft_util_token_free(cmds));
			if (parse.flag == true)
				return (cmds);
		}
		else
			parse.i++;
	}
	return (cmds);
}

static int	ft_util_token_split(t_parse *parse, const char *cmd)
{
	if (ft_isblank(cmd[parse->i]))
	{
		while (ft_isblank(cmd[parse->i]))
			(parse->i)++;
		if (ft_util_str_strchr("<>|\0", cmd[parse->i]) == false)
			parse->token_amount++;
	}
	else if (ft_util_str_strchr("<>|", cmd[parse->i]))
	{
		(parse->i)++;
		parse->token_amount++;
		if (ft_util_str_strchr("<>", cmd[parse->i - 1]))
		{
			if (cmd[parse->i] == '>' || cmd[parse->i] == '<')
				(parse->i)++;
			if (ft_util_str_strchr("\t \0", cmd[parse->i]) == false)
			{
				(parse->i)++;
				parse->token_amount++;
			}
		}
	}
	return (parse->token_amount);
}

static int	ft_util_token_count(char *cmd)
{
	static char	*pool_symbols = "<>|\t ";
	t_parse		parse;

	parse = ft_init_parse_data();
	parse.token_amount = 1;
	while (cmd[parse.i])
	{
		if (cmd[parse.i] == '\\' && parse.quotes.one == false
			&& cmd[parse.i + 1] != '\0')
			parse.i++;
		ft_util_quote_status(&parse.quotes, cmd[parse.i]);
		if (ft_util_str_strchr(pool_symbols, cmd[parse.i]) == true
			&& parse.quotes.one == false && parse.quotes.two == false)
			parse.token_amount = ft_util_token_split(&parse, cmd);
		else
			parse.i++;
	}
	return (parse.token_amount);
}

t_bool	ft_util_token_process(t_shell *shell, char **commands, t_env_list *env_list)
{
	char	**cmds;
	char	*cmd;
	t_parse	parse;
	t_token	*final;

	final = NULL;
	parse = ft_init_parse_data();
	while (commands[parse.i])
	{
		cmd = ft_util_str_tab_trim(commands[parse.i++]);
		if (cmd == NULL)
			ft_error_throw(ERROR_MALLOC);
		parse.token_amount = ft_util_token_count(cmd);
		cmds = ft_util_token_put(cmd, parse.token_amount);
		if (cmds == NULL)
			ft_error_throw(ERROR_MALLOC);
		ft_util_envcase_token(cmds);
		final = ft_util_token_to_struct(cmds, &final);
		ft_util_token_free_process(cmd, cmds);
	}
	ft_util_quote_plus(final);
	ft_util_token_addon(final);
	ft_run_token(shell, final, env_list);
	ft_util_token_free(final);
	return (TRUE);
}
