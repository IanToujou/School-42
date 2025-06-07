/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:37:09 by ibour             #+#    #+#             */
/*   Updated: 2025/06/06 09:48:05 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_child_process(t_child_process_info *info)
{
	int	j;

	j = 0;
	while (j < info->pipe_count)
	{
		if (j != info->i - 1)
			close(info->pipe_info->pipes[j][0]);
		if (j != info->i)
			close(info->pipe_info->pipes[j][1]);
		j++;
	}
	if (info->i > 0)
	{
		if (dup2(info->pipe_info->pipes[info->i - 1][0], STDIN_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(info->pipe_info->pipes[info->i - 1][0]);
	}
	if (info->i < info->pipe_info->cmd_count - 1)
	{
		if (dup2(info->pipe_info->pipes[info->i][1], STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(info->pipe_info->pipes[info->i][1]);
	}
	ft_parse_handle_execute(info->shell, info->cmds[info->i], info->env_list);
	exit(EXIT_FAILURE);
}

static size_t	calculate_total_length(char **array, const char *sep)
{
	size_t	total_len;
	int		i;

	total_len = 0;
	i = 0;
	while (array[i])
	{
		total_len += strlen(array[i]);
		if (array[i + 1])
			total_len += strlen(sep);
		i++;
	}
	return (total_len);
}

static char	*append_string(char *result, const char *to_append)
{
	char	*temp;

	temp = ft_strjoin(result, to_append);
	if (!temp)
	{
		free(result);
		return (NULL);
	}
	free(result);
	return (temp);
}

char	*ft_strjoin_array(char **array, const char *sep)
{
	char	*result;
	int		i;

	if (!array || !sep)
		return (NULL);
	result = malloc(calculate_total_length(array, sep) + 1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	i = 0;
	while (array[i])
	{
		result = append_string(result, array[i]);
		if (!result)
			return (NULL);
		if (array[i + 1])
		{
			result = append_string(result, sep);
			if (!result)
				return (NULL);
		}
		i++;
	}
	return (result);
}

int	open_redirection_file(char **parts, int *fd_out)
{
	int	i;

	i = 0;
	while (parts[i])
	{
		if (ft_strcmp(parts[i], ">") == 0 && parts[i + 1])
		{
			*fd_out = open(parts[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (*fd_out == -1)
				return (0);
			parts[i] = NULL;
			return (1);
		}
		i++;
	}
	return (1);
}
