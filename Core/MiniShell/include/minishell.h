/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:50:27 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 01:07:07 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../lib/libft/include/libft.h"
# include "errortype.h"
# include "bool.h"
# include "status.h"
# include "redirect.h"
# include "token.h"

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

# define PROCESS_LEVEL_DEFAULT 0
# define PROCESS_LEVEL_CHILD 1
# define PROCESS_LEVEL_PARENT 2

# define COLOR_ORANGE "\001\033[38;5;214m\002"
# define COLOR_GREEN "\001\033[38;5;120m\002"
# define COLOR_YELLOW "\001\033[38;5;228m\002"
# define COLOR_BLUE "\001\033[38;5;81m\002"
# define COLOR_MAGENTA "\001\033[38;5;177m\002"
# define COLOR_CYAN "\001\033[38;5;51m\002"
# define COLOR_PINK "\001\033[38;5;218m\002"
# define COLOR_RESET "\001\033[0m\002"

# define BANNER_LINE1 "　　　　 🌸＞　　フ"
# define BANNER_LINE2 "　　　　 | 　_　 _"
# define BANNER_LINE3 "　 　　 ／` ミ_wノ\t\t                        ▲    ▲"
# define BANNER_LINE4 "　　　 /　　　  |\t ▗▄▄▖▗▖ ▗▖▗▄▄▖ ▗▄▄▄▖▗▄▄▖  ▗▖  ▗▖▗▖  ▗▖▗▄▖🌸 ▗▄▄▖▗▖ ▗▖▗▄▄▄▖▗▖  ▗▖"
# define BANNER_LINE5 "　　 /　 ヽ　　 ﾉ\t▐▌   ▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌ ▐▛▚▖▐▌ ▝▚▞▘▐▌ ▐▌ ▐▌   ▐▌ ▐▌▐▌   ▐▌  ▐▌"
# define BANNER_LINE6 " 　 │　　|　|　|\t ▝▀▚▖▐▌ ▐▌▐▛▀▘ ▐▛▀▀▘▐▛▀▚▖ ▐▌ ▝▜▌  ▐▌ ▐▛▀▜▌  ▝▀▚▖▐▛▀▜▌▐▛▀▀▘▐▌  ▐▌"
# define BANNER_LINE7 "／￣|　　 |　|　|\t▗▄▄▞▘▝▚▄▞▘▐▌   ▐▙▄▄▖▐▌ ▐▌ ▐▌  ▐▌  ▐▌ ▐▌ ▐▌ ▗▄▄▞▘▐▌ ▐▌▐▙▄▄▖▐▙▄▄▐▙▄▄▖"
# define BANNER_LINE8 "| (￣ヽ＿_ヽ_)__)"
# define BANNER_LINE9 "＼二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二二つ"

typedef struct s_quotes
{
	t_bool	two;
	t_bool	one;
}	t_quotes;

typedef struct s_env
{
	char						*key;
	char						*value;
}								t_env;

typedef	struct s_env_list
{
	t_env						*current;
	struct s_env_list			*next;
}								t_env_list;


typedef struct s_shell
{
	int							exit_status;
	t_bool						is_running;
	t_bool						is_interactive;
	char						*temp_file;
	int							std_in;
	int							std_out;
	int							f_in;
	int							f_out;
	int							process_level;
	int							shlvl;
	pid_t						pid;
}								t_shell;

// init
t_bool							ft_init_env(t_shell *shell,
									t_env_list **env_list, char **env);
t_bool							ft_init_temp(t_shell *shell);
t_bool							ft_init_std(t_shell *shell);
void							ft_init_shell(t_env_list *env_list, t_shell *shell);
t_quotes						ft_init_quote(void);

// error
void							ft_error_throw(int error);

// signal
void							ft_signal_mask(void);
void							ft_signal_start(void);
void							ft_signal_c_fork(int signal);
void							ft_signal_c_fork_slash(int signal);
void							ft_signal_add_ignore(int signal);
void							ft_signal_heredoc(int signal);
void							ft_signal_empty(int signal);

// util
char							*ft_util_env_get(t_env_list **env_list,
									const char *key);
void							ft_util_env_var_add(t_env_list **env_list,
									char *var);
void							ft_util_env_var_remove(t_env_list **env_list,
									const char *key);
void							ft_util_banner_intro(void);
const char						*ft_util_banner_prompt_pre(void);
const char						*ft_util_banner_prompt_post(void);
t_bool							ft_util_str_tab_skip(const char *str);
char							*ft_util_str_tab_trim(const char *str);
t_bool							ft_util_quote_set(t_quotes *quotes, char c);
t_bool							ft_util_quote_is_outside(const t_quotes *quotes);
t_bool							ft_util_num_isnumber(const char *str);
t_bool							ft_util_redirect_check(char *str, int *i, char *user);

// parse
void							ft_parse_env(t_env_list **env_list, char **env);
t_bool							ft_parse_input(t_shell *shell, t_env_list *env_list, char *input, char *user);
int								ft_parse_handle(t_shell *shell, t_env_list *env, char *str);

// exit
t_bool							ft_exit_std(const t_shell *shell);
void							ft_exit_env(t_env_list **env_list);
void							ft_exit_temp(const t_shell *shell);

// run
void							ft_run_cmd(t_shell *shell, t_token *token, t_env_list *env_list);
t_bool							ft_run_defined_is_defined(const t_token *token);
void							ft_run_defined(t_shell *shell, t_token *token, t_env_list *env_list);

//cmd
void							ft_cmd_exit(t_shell *shell, t_env_list **env_list, t_token *token);

#endif
