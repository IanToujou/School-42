/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:50:27 by ibour             #+#    #+#             */
/*   Updated: 2025/03/03 01:58:11 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "errortype.h"
# include "boolean.h"

#include <stddef.h>
#include <sys/types.h>

typedef struct s_env {
	char	*key;
	char	*value;
}	t_env;

typedef struct s_env_list {
	t_env				*current;
	struct s_env_list	*next;
}	t_env_list;

typedef struct s_shell
{
	int		exit_status;
	pid_t	pid;
}	t_shell;

#endif
