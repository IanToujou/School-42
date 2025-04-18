/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_envcase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:09:04 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 13:12:30 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_bool	ft_util_envcase_check_reg(char *str)
{
	char	*result;

	if (str == NULL || ft_strlen(str) != 3)
		return (FALSE);
	result = ft_util_str_tolower(str);
	if (result == NULL)
		return (FALSE);
	if (ft_strncmp(result, "env", 4) != 0)
	{
		free(result);
		return (FALSE);
	}
	free(result);
	return (TRUE);
}

static t_bool	ft_util_envcase_check_around(const char *left, const char *right)
{
	if (left)
	{
		while (*left)
		{
			if (ft_util_str_strchr("<>|;", *left))
			{
				left++;
				continue ;
			}
			return (FALSE);
		}
	}
	if (right)
	{
		while (*right)
		{
			if (ft_util_str_strchr("<>|;", *right))
			{
				right++;
				continue ;
			}
			return (FALSE);
		}
	}
	return (TRUE);
}

void	ft_util_envcase_token(char **cmds)
{
	int	i;

	i = -1;
	while (cmds[++i])
	{
		if ((i == 0 && ft_util_envcase_check_reg(cmds[i]))
			|| (cmds[i + 1] == NULL
				&& ft_util_envcase_check_reg(cmds[i])
				&& ft_util_envcase_check_around(cmds[i - 1], NULL))
			|| (i != 0 && cmds[i + 1] != NULL
				&& ft_util_envcase_check_reg(cmds[i])
				&& ft_util_envcase_check_around(cmds[i - 1], cmds[i + 1])))
		{
			free(cmds[i]);
			cmds[i] = NULL;
			cmds[i] = ft_strdup("env");
			if (cmds[i] == NULL)
				ft_error_throw(ERROR_MALLOC);
		}
	}
}
