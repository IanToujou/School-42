/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:34:01 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 13:48:38 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_bool	ft_util_cmd_invalid_str(const char *str, const int pipe, int i)
{
	int	count_pipe;

	while (ft_isblank(str[++i]))
		;
	if (i + 1 > (int)ft_strlen(str))
		return (true);
	i = -1;
	count_pipe = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '|')
			count_pipe++;
		else if (ft_isblank(str[i]) == false || str[i] != '|')
			return (false);
	}
	if (count_pipe >= pipe)
		return (true);
	return (false);
}

static char	**split_exit(t_shell *shell)
{
	shell->exit_status = ERROR_MALLOC;
	return (NULL);
}

static char	*ft_util_cmd_parse_additional(t_env_list *env_list, const char *str,
									t_parse *parse, t_shell *shell)
{
	char	*str_without_space;
	char	*str_command;

	str_without_space = ft_util_str_tab_trim(str);
	if (str_without_space == NULL)
		ft_error_throw(ERROR_MALLOC);
	str_command = ft_util_cmd_grow_str(env_list, str_without_space, shell, &parse->flag);
	if (str_command == NULL && parse->flag == false)
		ft_error_throw(ERROR_MALLOC);
	if (ft_util_cmd_invalid_str(str_command, parse->pipe, -1) == true)
	{
		parse->flag = true;
		free(str_command);
		str_command = NULL;
	}
	if (str_without_space)
		free(str_without_space);
	return (str_command);
}

static char	*ft_util_cmd_split_new(char *str, t_parse *parse)
{
	char	*new;

	if (str[parse->i] != '\0')
		if (str[parse->i] != ';' && str[parse->i + 1] == '\0')
			(parse->i)++;
	if (str[parse->i] == ';' && ft_isblank(str[parse->i - 1])
		&& parse->i - 2 >= 0 && ft_isblank(str[parse->i - 2]))
		new = ft_substr(str, parse->begin_str, parse->i - parse->begin_str - 2);
	else if ((str[parse->i] == ';' && ft_isblank(str[parse->i - 1]))
		|| (str[parse->i - 1] && ft_isblank(str[parse->i - 1])
			&& str[parse->i - 2] && !ft_isblank(str[parse->i - 2])
			&& str[parse->i] == '\0'))
		new = ft_substr(str, parse->begin_str, parse->i - parse->begin_str - 1);
	else
		new = ft_substr(str, parse->begin_str, parse->i - parse->begin_str);
	if (new == NULL)
		ft_error_throw(ERROR_MALLOC);
	return (new);
}

char	**ft_util_cmd_split(t_env_list *env_list, char *str, t_parse *parse, t_shell *shell)
{
	char	*new;
	char	*cmd;

	new = ft_util_cmd_split_new(str, parse);
	if (ft_search_dollar(new) == true)
	{
		cmd = ft_util_cmd_parse_additional(env_list, new, parse, shell);
		free(new);
		new = NULL;
		if ((cmd == NULL && parse->flag == false) || (parse->flag == true))
			return (split_exit(shell));
		return (ft_util_cmd_get_cmds(cmd, parse->pipe));
	}
	return (ft_util_cmd_get_cmds(new, parse->pipe));
}
