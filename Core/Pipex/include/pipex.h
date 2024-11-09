/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:17:09 by ibour             #+#    #+#             */
/*   Updated: 2024/11/09 21:45:43 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "errortype.h"
# include "../lib/libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

void	ft_throw_error(int error);
void	ft_process_child(char **argv, char **envp, int *fd);
void	ft_process_parent(char **argv, char **envp, const int *fd);
void	ft_process_execute(char *argv, char **envp);

#endif
