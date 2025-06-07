/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_token_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:21:17 by ibour             #+#    #+#             */
/*   Updated: 2025/06/04 14:35:16 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_util_token_split(t_parse *parse, const char *cmd)
{
	if (ft_isblank(cmd[parse->i]))
	{
		while (ft_isblank(cmd[parse->i]))
			(parse->i)++;
		if (!ft_util_str_strchr("<>|\0", cmd[parse->i]))
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
			if (!ft_util_str_strchr("\t \0", cmd[parse->i]))
			{
				(parse->i)++;
				parse->token_amount++;
			}
		}
	}
	return (parse->token_amount);
}

int	ft_util_token_count(char *cmd)
{
	static char	*pool_symbols = "<>|\t ";
	t_parse		parse;

	parse = ft_init_parse_data();
	parse.token_amount = 1;
	while (cmd[parse.i])
	{
		if (cmd[parse.i] == '\\' && !parse.quotes.one
			&& cmd[parse.i + 1] != '\0')
			parse.i++;
		ft_util_quote_status(&parse.quotes, cmd[parse.i]);
		if (ft_util_str_strchr(pool_symbols, cmd[parse.i])
			&& !parse.quotes.one && !parse.quotes.two)
			parse.token_amount = ft_util_token_split(&parse, cmd);
		else
			parse.i++;
	}
	return (parse.token_amount);
}

t_token	*ft_util_token_process_loop(char **commands, t_shell *shell)
{
	t_parse	parse;
	char	**cmds;
	char	*cmd;
	t_token	*final;

	parse = ft_init_parse_data();
	final = NULL;
	while (commands[parse.i])
	{
		cmd = ft_util_str_tab_trim(commands[parse.i++]);
		if (cmd == NULL)
			ft_error_throw(ERROR_MALLOC);
		parse.token_amount = ft_util_token_count(cmd);
		cmds = ft_util_token_put(cmd, parse.token_amount);
		if (cmds == NULL)
		{
			free(cmd);
			ft_error_throw(ERROR_MALLOC);
		}
		ft_util_envcase_token(cmds);
		final = ft_util_token_to_struct(cmds, shell);
		ft_util_token_free_process(cmd, cmds);
	}
	return (final);
}

t_bool	ft_util_token_process(t_shell *shell, char **commands,
		t_env_list *env_list)
{
	t_token	*final;

	final = ft_util_token_process_loop(commands, shell);
	ft_util_quote_plus(final);
	ft_util_token_addon(final);
	ft_run_token(shell, final, env_list, commands);
	ft_util_token_cleanup(shell, final);
	return (TRUE);
}
