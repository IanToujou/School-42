/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:38:51 by ibour             #+#    #+#             */
/*   Updated: 2024/11/11 08:29:37 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_process_parent(char **argv, char **envp, const int *fd)
{
	int	out;

	out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out < 0)
		ft_throw_error(ERROR_FILE);
	dup2(fd[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(fd[1]);
	ft_process_execute(argv[3], envp);
}
