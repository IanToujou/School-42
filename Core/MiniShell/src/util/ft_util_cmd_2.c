/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_cmd_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:36:31 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 13:38:02 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**ft_util_cmd_free(char **cmds)
{
	int	i;

	i = -1;
	if (cmds != NULL)
	{
		while (cmds[++i])
			free(cmds[i]);
		free(cmds);
	}
	return (NULL);
}

static char	**ft_util_cmd_one(char *str)
{
	char	**cmd;

	cmd = (char **)ft_calloc(2, sizeof(char *));
	if (cmd == NULL)
		ft_error_throw(ERROR_MALLOC);
	cmd[0] = ft_strdup(str);
	if (cmd[0] == NULL)
		ft_error_throw(ERROR_MALLOC);
	cmd[1] = NULL;
	return (cmd);
}

static char	*ft_util_cmd_take(t_parse *parse, char *str)
{
	char	*command;

	command = ft_substr(str, parse->begin_str, parse->i - parse->begin_str + 1);
	if (command == NULL)
		ft_error_throw(ERROR_MALLOC);
	parse->begin_str = parse->i + 1;
	while (ft_isblank(str[parse->begin_str]) == true
		&& parse->quotes.two == false && parse->quotes.one == false)
		parse->begin_str++;
	return (command);
}

static char	**ft_util_cmd_get_more(char *str, int pipe)
{
	char	**cmds;
	t_parse	parse;
	int		j;

	parse = ft_init_parse_data();
	cmds = (char **)ft_calloc(pipe + 2, sizeof(char *));
	if (cmds == NULL)
		ft_error_throw(ERROR_MALLOC);
	j = 0;
	while (str[parse.i])
	{
		ft_util_quote_status(&parse.quotes, str[parse.i]);
		if ((str[parse.i] == '|' && parse.quotes.two == false
				&& parse.quotes.one == false) || str[parse.i + 1] == '\0')
		{
			cmds[j++] = ft_util_cmd_take(&parse, str);
			if (cmds[j - 1] == NULL)
				return (ft_util_cmd_free(cmds));
		}
		if (parse.quotes.two == true && str[parse.i] == '\\')
			parse.i += 2;
		else if (str[parse.i] != '\0')
			parse.i++;
	}
	return (cmds);
}

char	**ft_util_cmd_get_cmds(char *str, const int pipe)
{
	char	**cmds;

	cmds = NULL;
	if (pipe < 1)
		cmds = ft_util_cmd_one(str);
	else
		cmds = ft_util_cmd_get_more(str, pipe);
	free(str);
	str = NULL;
	if (cmds == NULL)
		return (NULL);
	return (cmds);
}
