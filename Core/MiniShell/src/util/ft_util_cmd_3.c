/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_cmd_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:45:02 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 13:48:51 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_util_cmd_sizeall(t_parse *parse, const char *str, int i)
{
	int		size;

	size = 0;
	while (str[++i] != '\0')
	{
		ft_util_quote_status(&parse->quotes, str[i]);
		if (str[i] == '$' && ft_isblank(str[i + 1]) == false
			&& parse->quotes.one == false)
			return (size);
		size++;
	}
	return (size);
}

static char	*ft_util_cmd_to_env(t_env_list *env, t_parse *parse, char *str,
							t_shell *shell)
{
	char	*transform;

	transform = NULL;
	if (str[parse->i] == '$' && ft_isblank(str[parse->i + 1]) == false
		&& parse->quotes.one == false)
	{
		transform = ft_parse_dollar(env, parse, str, shell);
		if (transform == NULL)
			ft_error_throw(ERROR_MALLOC);
	}
	else
	{
		parse->size = ft_util_cmd_sizeall(parse, str, parse->i - 1);
		transform = ft_substr(str, parse->i, parse->size);
		if (transform == NULL)
			ft_error_throw(ERROR_MALLOC);
		parse->i += (parse->size - 1);
	}
	return (transform);
}

static t_bool	ft_util_cmd_cat(char *value, char **cmd)
{
	char	*temp;

	if (*cmd == NULL)
	{
		*cmd = ft_strdup(value);
		if (*cmd == NULL)
			ft_error_throw(ERROR_MALLOC);
		return (TRUE);
	}
	temp = ft_strdup(*cmd);
	if (temp == NULL)
		ft_error_throw(ERROR_MALLOC);
	free(*cmd);
	*cmd = ft_strjoin(temp, value);
	free(temp);
	if (*cmd == NULL)
		ft_error_throw(ERROR_MALLOC);
	return (TRUE);
}

static char	*ft_util_cmd_grow_free(char *transform, char *cmd, t_shell *shell)
{
	shell->exit_status = ERROR_MALLOC;
	if (transform != NULL)
		free(transform);
	if (cmd != NULL)
		free(cmd);
	return (NULL);
}

char	*ft_util_cmd_grow_str(t_env_list *env_list, char *str, t_shell *shell, t_bool *flag)
{
	t_parse	parse;
	char	*transform;
	char	*cmd;

	parse = ft_init_parse_data();
	transform = NULL;
	cmd = NULL;
	while (str[parse.i] != '\0')
	{
		transform = ft_util_cmd_to_env(env_list, &parse, str, shell);
		if (transform == NULL)
			return (ft_util_cmd_grow_free(transform, cmd, shell));
		if (ft_util_cmd_cat(transform, &cmd) == FALSE)
			return (ft_util_cmd_grow_free(transform, cmd, shell));
		if (transform)
		{
			free(transform);
			transform = NULL;
		}
		parse.i++;
	}
	if (cmd == NULL)
		*flag = TRUE;
	return (cmd);
}