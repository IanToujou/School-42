/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:50:27 by ibour             #+#    #+#             */
/*   Updated: 2025/06/07 16:03:51 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../lib/libft/include/libft.h"
# include "banner.h"
# include "bool.h"
# include "errortype.h"
# include "redirect.h"
# include "status.h"
# include "token.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

# define TEMP_PATH "/tmp"
# define TEMP_FILE "/_tmpfile_shell"
# define SHLVL_DEFAULT 2

# define PROCESS_LEVEL_DEFAULT 0
# define PROCESS_LEVEL_CHILD 1
# define PROCESS_LEVEL_PARENT 2
# define PROCESS_LEVEL_ERROR -1

typedef struct s_quotes
{
	t_bool				two;
	t_bool				one;
	t_bool				none;
}						t_quotes;

typedef struct s_parse
{
	t_quotes			quotes;
	int					i;
	int					begin_str;
	int					pipe;
	int					size;
	t_bool				flag;
	int					token_amount;
	int					index_token;
}						t_parse;

typedef struct s_env
{
	char				*key;
	char				*value;
}						t_env;

typedef struct s_env_list
{
	t_env				*current;
	struct s_env_list	*next;
}						t_env_list;

typedef struct s_garbage
{
	void				*result;
	t_list				*tokens;
}						t_garbage;

typedef struct s_split_pipe
{
	int					i;
	int					start;
	int					count;
	int					in_quotes;
	char				quote_char;
}						t_split_pipe;

typedef struct s_split_cmd
{
	int					i;
	int					j;
	int					count;
	int					in_word;
	int					in_quotes;
}						t_split_cmd;

typedef struct s_handle_pipe
{
	int					i;
	int					j;
	int					cmd_count;
	pid_t				pid;

}						t_handle_pipe;

typedef struct s_handle_pipe_cmd
{
	int					pipes[10][2];
	int					pipe_count;
	int					i;
	int					cmd_count;
}						t_handle_pipe_cmd;

typedef struct s_shell
{
	int					exit_status;
	t_bool				is_running;
	t_bool				is_interactive;
	t_bool				executed;
	char				*temp_file;
	int					std_in;
	int					std_out;
	int					f_in;
	int					f_out;
	int					process_level;
	int					shlvl;
	pid_t				pid;
	t_garbage			*garbage;
	t_env_list			*env_list;
	char				**current_cmds;
	t_token				*current_token;
	int					pipe_count;
	t_bool				is_redirected;
}						t_shell;

typedef struct s_pipe_exec_info
{
	t_shell				*shell;
	char				**cmds;
	t_env_list			*env_list;
	t_handle_pipe_cmd	*pipe_info;
	pid_t				*pids;
}						t_pipe_exec_info;

typedef struct s_child_process_info
{
	int					i;
	int					pipe_count;
	t_handle_pipe_cmd	*pipe_info;
	t_shell				*shell;
	char				**cmds;
	t_env_list			*env_list;
}						t_child_process_info;

typedef struct s_execute_child_info
{
	char				**cmds;
	int					(*pipes)[2];
	int					i;
	int					cmd_count;
	t_env_list			*env_list;
}						t_execute_child_info;

typedef struct s_pipeline_info
{
	t_shell				*shell;
	char				**cmds;
	t_env_list			*env_list;
	int					pipes[11][2];
	pid_t				*pids;
}						t_pipeline_info;

t_bool					ft_init_env(t_shell *shell, t_env_list **env_list,
							char **env);
t_bool					ft_init_temp(t_shell *shell);
t_bool					ft_init_std(t_shell *shell);
void					ft_run_interactive_shell(t_env_list *env_list,
							t_shell *shell);
void					ft_run_non_interactive_shell(t_env_list *env_list,
							t_shell *shell);
char					*ft_read_all_stdin(void);
t_quotes				ft_init_quote(void);
t_parse					ft_init_parse_data(void);
t_bool					ft_init_token_data(char **cmds, t_parse *parse,
							char *str);

void					ft_error_throw(int error);

void					ft_signal_mask(t_shell *shell);
void					ft_signal_start(t_shell *shell);
void					ft_signal_c_fork(int signal);
void					ft_signal_c_fork_slash(int signal);
void					ft_signal_add_ignore(int signal);
void					ft_signal_heredoc(int signal);
void					ft_signal_empty(int signal);

char					*ft_util_env_get(t_env_list **env_list,
							const char *key);
void					ft_util_env_var_add(t_env_list **env_list, char *var);
void					ft_util_env_var_remove(t_env_list **env_list,
							const char *key);
void					ft_util_env_free(t_env_list *env_list);
void					ft_util_env_print_exported(t_env_list *env_list);
void					ft_util_env_update_shlvl(t_shell *shell,
							const t_token *token, t_env_list **env_list);
int						ft_is_valid_env_name(const char *str);
t_bool					ft_util_str_tab_skip(const char *str);
char					*ft_util_str_tab_trim(const char *str);
char					*ft_util_str_tolower(const char *str);
bool					ft_util_quote_status(t_quotes *quotes, char ch);
void					ft_util_quote_plus(t_token *cmds);
t_bool					ft_util_num_isnumber(const char *str);
t_bool					ft_util_str_strchr(const char *s, int c);
t_token					*ft_util_token_previous(t_token *token);
t_token					*ft_util_token_next(t_token *token);
t_token					*ft_util_token_create(const t_shell *shell,
							const char *content);
void					ft_util_token_add_back(t_token **list, t_token *new);
void					ft_util_env_set(t_env_list **env_list, const char *key,
							const char *value);
void					ft_util_token_free(t_token *list);
void					ft_util_token_cleanup(t_shell *shell, t_token *list);
char					**ft_util_token_put(char *str, const int amount);
void					ft_util_token_delete(void *ptr);
t_bool					ft_util_token_process(t_shell *shell, char **commands,
							t_env_list *env_list);
t_token					*ft_util_token_to_struct(char **cmds, t_shell *shell);
t_token					*ft_util_token_process_loop(char **commands,
							t_shell *shell);
void					ft_util_token_addon(t_token *token);
void					ft_util_envcase_token(char **cmds);
char					**ft_util_cmd_get_cmds(char *str, int pipe);
char					**ft_util_cmd_split(t_env_list *env_list, char *str,
							t_parse *parse, t_shell *shell);
char					*ft_util_cmd_grow_str(t_env_list *env_list, char *str,
							t_shell *shell, t_bool *flag);
char					**ft_util_cmd_free(char **cmds);
char					**ft_util_token_free_cmds(char **cmds);
void					ft_util_bin_signal(const t_token *token);
char					**ft_util_token_put(char *str, const int amount);
t_bool					ft_util_token_loop_step(char **cmds, t_parse *parse,
							char *str);
void					ft_util_bin_free_paths(char **paths,
							char *cmd_with_slash);
void					ft_util_launch_execve(t_env_list *env_list,
							char **args);
char					**ft_util_env_to_array(t_env_list **env_list);
int						ft_util_redirect_level(t_shell *shell, t_token *token,
							t_token *prev, t_env_list *env_list);
bool					ft_util_prev_redirect(t_token *token);
void					ft_util_handle_redirections(t_shell *shell,
							t_token *token);
void					ft_util_handle_input(t_shell *shell, t_token *token,
							t_env_list *env_list);
void					ft_util_handle_dobinp(t_shell *shell, t_token *token,
							t_env_list *env_list);
void					ft_util_handle_child_dobinp(int fd, char *eof);
void					ft_util_handle_parent_dobinp(t_shell *shell, int fd,
							pid_t pid, t_env_list *env_list);
int						ft_util_check_pipe_io(t_shell *shell, t_token *prev);
int						ft_util_handle_pipe(t_shell *shell);
int						ft_util_handle_child_pipe(t_shell *shell, int *fd);
int						ft_util_handle_parent_pipe(t_shell *shell, int *fd,
							pid_t pid);

void					ft_parse_env(t_env_list **env_list, char **env);
t_bool					ft_parse_input(t_shell *shell, t_env_list *env_list,
							const char *input, const char *user);
int						ft_parse_handle(t_shell *shell, t_env_list *env_list,
							char *str);
int						ft_parse_handle_extract_word(const char *str,
							char **result, int *i, int count);
void					ft_parse_handle_free_result(char **result, int count);
int						ft_parse_handle_count_words(const char *str);
char					*ft_parse_handle_strndup(const char *s, size_t n);
t_bool					ft_parse_handle_exit(char **cmd, t_shell *shell,
							t_bool status);
void					ft_parse_handle_setup_io(int pipes[][2], int pipe_count,
							int cmd_index, int cmd_count);
void					ft_parse_handle_close_pipes(int pipes[][2],
							int pipe_count);
t_bool					ft_parse_handle_setup_pipes(int pipes[][2],
							int pipe_count);
char					**ft_parse_handle_split_cmd(const char *cmd_str);
char					**ft_parse_handle_extract_words(const char *trimmed,
							int word_count);
int						ft_parse_handle_count_segments(const char *input);
t_bool					ft_parse_handle_pipe_cmd(t_shell *shell, char **cmds,
							t_env_list *env_list, int pipe_count);
void					ft_parse_handle_wait_children(int cmd_count);
void					ft_parse_handle_spawn_pipe(t_shell *shell, char **cmds,
							t_env_list *env_list, t_handle_pipe_cmd pipe_info);
void					ft_parse_handle_execute(t_shell *shell, char *cmd_str,
							t_env_list *env_list);
void					ft_parse_handle_update_quote(char c, int *in_quotes,
							char *quote_char);
t_bool					ft_parse_dollar_search(const char *str);
char					*ft_parse_dollar(t_env_list *env_list, t_parse *parse,
							const char *str, const t_shell *shell);
t_bool					ft_exit_std(const t_shell *shell);
void					ft_exit_env(t_env_list **env_list);
void					ft_exit_temp(const t_shell *shell);

void					ft_run_cmd(t_shell *shell, const t_token *token,
							t_env_list *env_list, char **args);
t_bool					ft_run_defined_is_defined(const t_token *token);
void					ft_run_defined(t_shell *shell, const t_token *token,
							t_env_list *env_list, char **cmd);
t_bool					ft_run_token(t_shell *shell, t_token *token,
							t_env_list *env_list, char **cmds);
void					ft_run_bin(t_shell *shell, const t_token *token,
							t_env_list *env_list, int pipe_count);
void					ft_run_bin_piped_prepare_existing(const t_shell *shell,
							char ***args, int *i);
char					**ft_run_bin_piped_allocate(int size);
void					ft_run_bin_piped_populate(char **args,
							const t_token *current, int size);
char					**ft_run_bin_piped_args(const t_token *token);
int						ft_run_bin_token_length(const t_token *token);

void					ft_cmd_cd(t_shell *shell, t_env_list **env_list,
							t_token *args);
void					ft_cmd_exit(t_shell *shell, t_env_list **env_list,
							t_token *token, char **cmd);
void					ft_cmd_env(t_shell *shell, t_env_list **env_list);
void					ft_cmd_echo(t_shell *shell, t_token *token);
void					ft_cmd_pwd(t_shell *shell);
char					*ft_cmd_pwd_get(void);
void					ft_cmd_export(t_shell *shell, t_env_list **env_list,
							t_token *args);
void					ft_cmd_export_handle_env(t_env_list **env_list,
							char *str);
void					ft_cmd_export_handle_env(t_env_list **env_list,
							char *str);
void					ft_cmd_unset(t_shell *shell, t_env_list **env_list,
							t_token *args);
void					ft_cmd_nya(void);

void					ft_util_banner_intro(void);
char					*ft_util_prompt(t_env_list *env_list);

bool					ft_util_quote_set(t_quotes *quotes, char ch);
bool					ft_util_quote_is_outside(const t_quotes *quotes);
bool					ft_util_check_seps(const char *str, int *i,
							const char *name);

bool					ft_util_is_whitespace(char c);
bool					ft_util_strchr(const char *s, int c);
bool					ft_util_redirect_check(const char *str, int *i,
							const char *name);

bool					ft_error_syntax_token(char ch, const char *name);
bool					ft_error_redirect_check(int redirect_first,
							int redirect_second, const char *name);
char					**ft_parse_handle_split_pipes(const char *input);
t_bool					ft_parse_handle_exit(char **cmd, t_shell *shell,
							t_bool status);
t_bool					ft_handle_pipe_execution(t_shell *shell, char **cmds,
							t_env_list *env_list);
char					*ft_strjoin_array(char **array, const char *sep);
void					execute_with_redirection(t_shell *shell, char *cmd,
							t_env_list *env_list);
char					*parse_command_for_redirection(char *cmd,
							char **outfile);
t_bool					ft_util_token_free_process(char *cmd, char **cmds);

int						ft_util_create_pipe_and_fork(int fd[2], pid_t *pid);
t_token					*ft_create_cmd_token(char *cmd, int *i);
t_token					*ft_create_arg_token(char *cmd);
t_bool					ft_process_defined(t_shell *shell, t_token *cmd_token,
							char **commands, t_env_list *env_list);
t_bool					ft_process_execve(t_shell *shell, char **commands,
							t_env_list *env_list);
t_bool					ft_util_token_process_pipe_internal(t_shell *shell,
							char **commands, t_env_list *env_list,
							t_token *cmd_token);
int						find_redirection(char **parts, char **outfile);
char					**ft_parse_handle_clean_words(char **words);
char					*ft_parse_handle_clean_word(char *word);
void					ft_spawn_single_child(t_shell *shell, char *cmd,
							t_env_list *env_list, t_handle_pipe_cmd *pipe_info);
void					ft_child_process(t_child_process_info *info);
int						handle_redirection(char *cmd, int *fd_out);
char					*rebuild_command(char **parts);
int						open_redirection_file(char **parts, int *fd_out);
void					ft_wait_for_children(pid_t *pids, int cmd_count,
							t_shell *shell);
void					ft_close_all_pipes(int pipes[11][2], int pipe_count);
void					ft_execute_child(t_execute_child_info *info);
int						ft_count_commands(char **cmds);
t_bool					ft_create_pipes(int pipes[11][2], int cmd_count);
t_bool					ft_setup_input_redirection(char **cmd);
void					ft_setup_child_pipes(int pipes[11][2], int i,
							int cmd_count);
t_bool					ft_execute_pipeline(t_pipeline_info *info);
char					*ft_strjoin_free(char *s1, char *s2);
void					ft_handle_escape_sequences(const char *str, int *i);
void					ft_cmd_echo_print_args(t_shell *shell, t_token *token);
void					ft_print_quoted_single(t_shell *shell, char *str);
#endif
