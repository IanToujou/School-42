/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:09:13 by ibour             #+#    #+#             */
/*   Updated: 2025/04/16 22:02:59 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	ft_parse_exit_args(t_shell *shell, char **args)
{
	long	exit_code;

	if (!args[1])
		return (shell->exit_status);
	if (args[2])
	{
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
		return (-1);
	}
	if (ft_is_numeric(args[1]))
	{
		exit_code = ft_atol(args[1]);
		return (exit_code);
	}
	else
	{
		ft_putstr_fd("exit: numeric argument required\n", STDERR_FILENO);
		return (255);
	}
}

void	ft_handle_exit(t_shell *shell, char *buffer)
{
	char	**args;
	int		exit_code;

	args = ft_split(buffer, ' ');
	free(buffer);
	if (!args)
		exit(shell->exit_status);
	exit_code = ft_parse_exit_args(shell, args);
	ft_free_split(args);
	if (exit_code != -1)
		exit((unsigned char)exit_code);
}
