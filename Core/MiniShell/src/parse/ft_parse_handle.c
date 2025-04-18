/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:47:10 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 14:33:15 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_bool	ft_parse_handle_exit(char **cmd, t_shell *shell, t_bool status)
{
	int		i;

	i = -1;
	if (cmd)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
	}
	if (status)
		return (true);
	shell->exit_status = STATUS_MALLOC;
	return (false);
}

static t_bool	ft_parse_handle_process(t_shell *shell, t_parse *parse, t_env_list *env_list, char *str)
{
	char	**cmd;

	cmd = ft_util_cmd_split(env_list, str, parse, shell);
	if (cmd == NULL && parse->flag == false)
		return (false);
	parse->pipe = 0;
	parse->begin_str = parse->i + 1;
	if (parse->flag == true)
		return (true);
	if (ft_util_token_process(shell, cmd, env_list) == false)
		return (ft_parse_handle_exit(cmd, shell, false));
	return (ft_parse_handle_exit(cmd, shell, true));
}

t_bool	ft_parse_handle(t_shell *shell, t_env_list *env_list, char *str)
{
	t_parse	data;

	data = ft_init_parse_data();
	while (str[data.i])
	{
		ft_util_quote_status(&data.quotes, str[data.i]);
		if (str[data.i] == '\0' || (str[data.i] == ';'
				&& ft_util_quote_is_outside(&data.quotes) == TRUE)
			|| str[data.i + 1] == '\0')
		{
			data.flag = FALSE;
			if (ft_parse_handle_process(shell, &data, env_list, str) == FALSE)
				return (FALSE);
		}
		if (str[data.i] == '|'
			&& ft_util_quote_is_outside(&data.quotes) == TRUE)
			data.pipe++;
		if (str[data.i] == '\\' && data.quotes.two == TRUE)
			data.i += 2;
		else if (str[data.i] != '\0')
			data.i++;
	}
	return (TRUE);
}
