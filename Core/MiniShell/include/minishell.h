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
# include <readline/history.h>
# include <signal.h>
# include <termios.h>

# define TEMP_PATH "/tmp"
# define TEMP_FILE "/_tmpfile_shell"
# define SHLVL_DEFAULT 2

# define O     "\001\033[38;5;214m\002"
# define G     "\001\033[38;5;120m\002"
# define Y     "\001\033[38;5;228m\002"
# define B     "\001\033[38;5;81m\002"
# define M     "\001\033[38;5;177m\002"
# define C     "\001\033[38;5;51m\002"
# define P     "\001\033[38;5;218m\002"
# define RESET "\001\033[0m\002"

# define PROMPT \
    O "🐱" RESET \
    G "S" RESET \
    Y "u" RESET \
    B "p" RESET \
    M "e" RESET \
    C "r" RESET \
    Y "~" RESET \
    P "N" RESET \
    P "y" RESET \
    P "a" RESET \
    Y "~" RESET \
    G "S" RESET \
    Y "h" RESET \
    B "e" RESET \
    Y "l" RESET \
    B "l" RESET \
    M "🐱" RESET \
    O ">" RESET \
    P "$" RESET \
    Y " "

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

//init
t_bool	ft_init_env(t_shell *shell, t_env_list *env_list, char **env);
t_bool	ft_init_temp(t_shell *shell);
t_bool	ft_init_std(t_shell *shell);

extern volatile sig_atomic_t g_signal_status;
void	restore_terminal(void);
void	ft_echo_off(void);
void	ft_set_sig(void);
void	ft_sigint(int sig);

//error
void	ft_error_throw(int error);

//util
char	*ft_util_env_get(t_env_list **env_list, const char *key);
void	ft_util_env_var_add(t_env_list **env_list, char *var);
void	ft_util_env_var_remove(t_env_list **env_list, const char *key);
void	ft_util_banner(void);
void ft_handle_exit(t_shell *shell, char *buffer);
int	ft_is_numeric(const char *str);
void	ft_free_split(char **split);

//parse
void	ft_parse_env(t_env_list **env_list, char **env);

//exit
t_bool	ft_exit_std(const t_shell *shell);
void	ft_exit_env(t_env_list **env_list);

//main
void ft_init_shell_loop(t_shell *shell, t_env_list *env_list);
void ft_init_shell(t_shell *shell, t_env_list *env_list);


#endif
