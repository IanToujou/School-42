/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:50:27 by ibour             #+#    #+#             */
/*   Updated: 2025/04/19 12:40:08 by ibour            ###   ########.fr       */
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
# include "banner.h"

# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
# include <errno.h>

# define TEMP_PATH "/tmp"
# define TEMP_FILE "/_tmpfile_shell"
# define SHLVL_DEFAULT 2

# define PROCESS_LEVEL_DEFAULT 0
# define PROCESS_LEVEL_CHILD 1
# define PROCESS_LEVEL_PARENT 2

typedef struct s_quotes
{
	t_bool	two;
	t_bool	one;
}	t_quotes;

typedef struct s_parse
{
	t_quotes	quotes;
	int			i;
	int			begin_str;
	int			pipe;
	int			size;
	t_bool		flag;
	int			token_amount;
	int			index_token;
}			t_parse;

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
	t_bool						is_running;
	t_bool						is_interactive;
	t_bool						executed;
	char						*temp_file;
	int							std_in;
	int							std_out;
	int							f_in;
	int							f_out;
	int							process_level;
	int							shlvl;
	pid_t						pid;
}								t_shell;

t_bool		ft_init_env(t_shell *shell, t_env_list **env_list, char **env);
t_bool		ft_init_temp(t_shell *shell);
t_bool		ft_init_std(t_shell *shell);
void		ft_init_shell(t_env_list *env_list, t_shell *shell);
t_quotes	ft_init_quote(void);
t_parse		ft_init_parse_data(void);
t_bool		ft_init_token_data(char **cmds, t_parse *parse, char *str);

void		ft_error_throw(int error);

void		ft_signal_mask(void);
void		ft_signal_start(void);
void		ft_signal_c_fork(int signal);
void		ft_signal_c_fork_slash(int signal);
void		ft_signal_add_ignore(int signal);
void		ft_signal_heredoc(int signal);
void		ft_signal_empty(int signal);

char		*ft_util_env_get(t_env_list **env_list, const char *key);
void		ft_util_env_var_add(t_env_list **env_list, char *var);
void		ft_util_env_var_remove(t_env_list **env_list, const char *key);
void		ft_util_env_free(t_env_list	*env_list);
t_bool		ft_util_str_tab_skip(const char *str);
char		*ft_util_str_tab_trim(const char *str);
char		*ft_util_str_tolower(const char *str);
t_bool		ft_util_quote_status(t_quotes *quotes, char c);
t_bool		ft_util_quote_is_outside(const t_quotes *quotes);
void		ft_util_quote_plus(t_token *cmds);
t_bool		ft_util_num_isnumber(const char *str);
t_bool		ft_util_str_strchr(const char *s, int c);
t_token		*ft_util_token_previous(t_token	*token);
t_token		*ft_util_token_next(t_token	*token);
t_token		*ft_util_token_create(const char *content);
void		ft_util_token_add_back(t_token **list, t_token *new);
void		ft_util_token_free(t_token *list);
int			ft_util_redirect_level(t_shell *shell, t_token *token,
				t_token *prev, t_env_list *env_list);
t_bool		ft_util_token_process(t_shell *shell, char **commands,
				t_env_list *env_list);
t_token		*ft_util_token_to_struct(char **cmds, t_token **final);
void		ft_util_token_addon(const t_token *token);
void		ft_util_envcase_token(char **cmds);
char		**ft_util_cmd_get_cmds(char *str, int pipe);
char		**ft_util_cmd_split(t_env_list *env_list, char *str,
				t_parse *parse, t_shell *shell);
char		*ft_util_cmd_grow_str(t_env_list *env_list, char *str,
				t_shell *shell, t_bool *flag);
char		**ft_util_token_free_cmds(char **cmds);

void		ft_parse_env(t_env_list **env_list, char **env);
t_bool		ft_parse_input(t_shell *shell, t_env_list *env_list,
				const char *input, char *user);
int			ft_parse_handle(t_shell *shell, t_env_list *env_list, char *str);
t_bool		ft_parse_dollar_search(const char *str);
char		*ft_parse_dollar(t_env_list *env_list, t_parse *parse,
				const char *str, const t_shell *shell);

t_bool		ft_exit_std(const t_shell *shell);
void		ft_exit_env(t_env_list **env_list);
void		ft_exit_temp(const t_shell *shell);

void		ft_run_cmd(t_shell *shell, t_token *token, t_env_list *env_list);
t_bool		ft_run_defined_is_defined(const t_token *token);
void		ft_run_defined(t_shell *shell, t_token *token,
				t_env_list *env_list);
t_bool		ft_run_token(t_shell *shell, t_token *token, t_env_list *env_list);
void		ft_run_bin(t_shell *shell, t_token *token, t_env_list *env_list);

void		ft_cmd_exit(t_shell *shell, t_env_list **env_list, t_token *token);

void		ft_util_banner_intro(void);
const char	*ft_util_banner_prompt_pre(void);
const char	*ft_util_banner_prompt_post(void);

#endif
