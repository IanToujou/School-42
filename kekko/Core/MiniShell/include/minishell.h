/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:50:27 by ibour             #+#    #+#             */
/*   Updated: 2025/04/10 10:42:14 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../lib/libft/include/libft.h"
# include "errortype.h"
# include "types.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <termios.h>
# include <unistd.h>

# define TEMP_PATH "/tmp"
# define TEMP_FILE "/_tmpfile_shell"
# define SHLVL_DEFAULT 2

# define O "\001\033[38;5;214m\002"
# define G "\001\033[38;5;120m\002"
# define Y "\001\033[38;5;228m\002"
# define B "\001\033[38;5;81m\002"
# define M "\001\033[38;5;177m\002"
# define C "\001\033[38;5;51m\002"
# define P "\001\033[38;5;218m\002"
# define RESET "\001\033[0m\002"

# define BANNER_LINE1 "　　　　 🌸＞　　フ"
# define BANNER_LINE2 "　　　　 | 　_　 _"
# define BANNER_LINE3 "　 　　 ／` ミ_wノ\t\t                        ▲    ▲"
# define BANNER_LINE4 "　　　 /　　　  |\t ▗▄▄▖▗▖ ▗▖▗▄▄▖ ▗▄▄▄▖▗▄▄▖  ▗▖  ▗▖▗▖  ▗▖▗▄▖🌸 ▗▄▄▖▗▖ ▗▖▗▄▄▄▖▗▖  ▗▖"
# define BANNER_LINE5 "　　 /　 ヽ　　 ﾉ\t▐▌   ▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌ ▐▛▚▖▐▌ ▝▚▞▘▐▌ ▐▌ ▐▌   ▐▌ ▐▌▐▌   ▐▌  ▐▌"
# define BANNER_LINE6 " 　 │　　|　|　|\t ▝▀▚▖▐▌ ▐▌▐▛▀▘ ▐▛▀▀▘▐▛▀▚▖ ▐▌ ▝▜▌  ▐▌ ▐▛▀▜▌  ▝▀▚▖▐▛▀▜▌▐▛▀▀▘▐▌  ▐▌"
# define BANNER_LINE7 "／￣|　　 |　|　|\t▗▄▄▞▘▝▚▄▞▘▐▌   ▐▙▄▄▖▐▌ ▐▌ ▐▌  ▐▌  ▐▌ ▐▌ ▐▌ ▗▄▄▞▘▐▌ ▐▌▐▙▄▄▖▐▙▄▄▐▙▄▄▖"
# define BANNER_LINE8 "| (￣ヽ＿_ヽ_)__)"
# define BANNER_LINE9 "＼二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二つ"

typedef struct s_env
{
	char						*key;
	char						*value;
}								t_env;

typedef struct s_env_list
{
	t_env						*current;
	struct s_env_list			*next;
}								t_env_list;

typedef struct s_shell
{
	int							exit_status;
	bool							is_interactive;
	char						*temp_file;
	int							std_in;
	int							std_out;
	int							shlvl;
	pid_t						pid;
}								t_shell;

// init
t_bool							ft_init_env(t_shell *shell,
									t_env_list *env_list, char **env);
t_bool							ft_init_temp(t_shell *shell);
t_bool							ft_init_std(t_shell *shell);

extern volatile sig_atomic_t	g_signal_status;
void							restore_terminal(void);
void							ft_echo_off(void);
void							ft_set_sig(void);
void							ft_sigint(int sig);

// error
void							ft_error_throw(int error);

// util
char							*ft_util_env_get(t_env_list **env_list,
									const char *key);
void							ft_util_env_var_add(t_env_list **env_list,
									char *var);
void							ft_util_env_var_remove(t_env_list **env_list,
									const char *key);
void							ft_util_banner(void);
const char						*get_prompt(void);
void							ft_handle_exit(t_shell *shell, char *buffer);
int								ft_is_numeric(const char *str);
void							ft_free_split(char **split);

// parse
void							ft_parse_env(t_env_list **env_list, char **env);

// exit
t_bool							ft_exit_std(const t_shell *shell);
void							ft_exit_env(t_env_list **env_list);

// main
void							ft_init_shell_loop(t_shell *shell,
									t_env_list *env_list);
void							ft_init_shell(t_shell *shell,
									t_env_list *env_list);

#endif
