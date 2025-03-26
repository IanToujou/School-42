/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:50:27 by ibour             #+#    #+#             */
/*   Updated: 2025/03/26 13:02:34 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../lib/libft/include/libft.h"
# include "errortype.h"
# include "types.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <readline/readline.h>

# define TEMP_PATH "/tmp"
# define TEMP_FILE "/_tmpfile_shell"
# define SHLVL_DEFAULT 2

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

typedef struct s_env_list
{
	t_env				*current;
	struct s_env_list	*next;
}	t_env_list;

typedef struct s_shell
{
	int		exit_status;
	char	*temp_file;
	int		std_in;
	int		std_out;
	int		shlvl;
	pid_t	pid;
}	t_shell;

t_bool	ft_init_env(t_shell *shell, t_env_list *env_list, char **env);
t_bool	ft_init_temp(t_shell *shell);
t_bool	ft_init_std(t_shell *shell);

void	ft_error_throw(int error);

char	*ft_util_env_get(t_env_list **env_list, const char *key);
void	ft_util_env_var_add(t_env_list **env_list, char *var);
void	ft_util_env_var_remove(t_env_list **env_list, const char *key);

void	ft_parse_env(t_env_list **env_list, char **env);

t_bool	ft_exit_std(const t_shell *shell);
void	ft_exit_env(t_env_list **env_list);

char	*ft_read_line(void); //TODO

#endif
