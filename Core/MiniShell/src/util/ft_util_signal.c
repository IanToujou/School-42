/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:35:16 by ibour             #+#    #+#             */
/*   Updated: 2025/04/10 10:10:42 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

void	ft_handle_exit(t_shell *shell, char *buffer)
{
	char	**args;
	long	exit_code;

	args = ft_split(buffer, ' ');
	if (!args)
		exit(shell->exit_status);
	if (!args[1])
		exit((unsigned char)shell->exit_status);
	if (args[2])
	{
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
		ft_free_split(args);
		return ;
	}
	if (ft_is_numeric(args[1]))
	{
		exit_code = ft_atol(args[1]);
		exit((unsigned char)exit_code);
	}
	else
	{
		ft_putstr_fd("exit: numeric argument required\n", STDERR_FILENO);
		ft_free_split(args);
		exit(255);
	}
}
