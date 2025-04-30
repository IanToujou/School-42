/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:38:00 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/04/23 16:40:14 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*ft_cmd_pwd_get(void)
{
	char	*cwd;
	size_t	buf_size;

	buf_size = 1024;
	cwd = malloc(buf_size);
	if (!cwd)
		ft_error_throw(ERROR_MALLOC);
	while (getcwd(cwd, buf_size) == NULL)
	{
		if (errno != ERANGE)
		{
			free(cwd);
			ft_error_throw(ERROR_GETCWD);
		}
		buf_size *= 2;
		free(cwd);
		cwd = malloc(buf_size);
		if (!cwd)
			ft_error_throw(ERROR_MALLOC);
	}
	return (cwd);
}

void	ft_cmd_pwd(t_shell *shell)
{
	char	*cwd;

	cwd = ft_cmd_pwd_get();
	ft_putstr_fd(cwd, shell->std_out);
	ft_putstr_fd("\n", shell->std_out);
	free(cwd);
	shell->exit_status = STATUS_OK;
}
