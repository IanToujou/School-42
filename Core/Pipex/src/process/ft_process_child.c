/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:38:51 by ibour             #+#    #+#             */
/*   Updated: 2024/11/09 22:45:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_process_child(char **argv, char **envp, int *fd)
{
	int	in;

	in = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (in < 0)
		ft_throw_error(ERROR_FILE);
	dup2(fd[1], STDOUT_FILENO);
	dup2(in, STDIN_FILENO);
	close(fd[0]);
	ft_process_execute(argv[2], envp);
}