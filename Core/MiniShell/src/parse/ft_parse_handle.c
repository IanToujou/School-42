/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:47:10 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 11:54:32 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_bool	ft_parse_handle_exit(char **cmd, t_shell *shell, t_bool status)
{
	int		i;

	i = -1;
	if (cmd)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
	}
	if (status)
		return (true);
	shell->exit_status = STATUS_MALLOC;
	return (false);
}

// Helper function to duplicate a string of specified length
char *ft_strndup(const char *s, size_t n)
{
	char *result;
	size_t len = 0;

	while (len < n && s[len])
		len++;

	result = (char *)malloc(len + 1);
	if (!result)
		return NULL;

	for (size_t i = 0; i < len; i++)
		result[i] = s[i];
	result[len] = '\0';

	return result;
}


static char **ft_split_command(const char *cmd_str)
{
	char **result = NULL;
	char *trimmed;
	int i = 0, j = 0, count = 0;
	int in_word = 0, in_quotes = 0;

	if (!cmd_str)
		return NULL;

	// Trim leading/trailing whitespace
	trimmed = ft_strtrim(cmd_str, " \t\n\r");
	if (!trimmed)
		return NULL;

	// Count arguments (handling quotes)
	while (trimmed[i]) {
		if (trimmed[i] == '"' || trimmed[i] == '\'')
			in_quotes = !in_quotes;

		if (!in_quotes && trimmed[i] == ' ' && in_word) {
			in_word = 0;
		} else if (!in_quotes && trimmed[i] != ' ' && !in_word) {
			in_word = 1;
			count++;
		}
		i++;
	}

	// Allocate array for arguments
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result) {
		free(trimmed);
		return NULL;
	}

	// Parse arguments
	i = 0;
	count = 0;
	while (trimmed[i]) {
		// Skip leading whitespace
		while (trimmed[i] && (trimmed[i] == ' ' || trimmed[i] == '|'))
			i++;

		if (!trimmed[i])
			break;

		// Start of an argument
		j = i;
		in_quotes = 0;

		// Find end of argument
		while (trimmed[i] && (in_quotes || trimmed[i] != ' ')) {
			if (trimmed[i] == '"' || trimmed[i] == '\'')
				in_quotes = !in_quotes;
			i++;
		}

		// Copy the argument
		result[count] = ft_strndup(trimmed + j, i - j);
		if (!result[count]) {
			// Free already allocated strings on failure
			while (--count >= 0)
				free(result[count]);
			free(result);
			free(trimmed);
			return NULL;
		}

		count++;
	}

	result[count] = NULL;
	free(trimmed);
	return result;
}

static t_bool ft_handle_piped_commands(t_shell *shell, char **cmds, t_env_list *env_list, const int pipe_count)
{
    int i;
    int cmd_count = 0;
    pid_t pid;
    int pipes[10][2];
    t_token *token;
    char **args;

    while (cmds[cmd_count] != NULL)
    	cmd_count++;

    // Create all necessary pipes
    for (i = 0; i < pipe_count; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe creation failed");
            // Clean up previously created pipes
            while (--i >= 0) {
                close(pipes[i][0]);
                close(pipes[i][1]);
            }
            return (false);
        }
    }

    for (i = 0; i < cmd_count; i++) {
        pid = fork();
        if (pid == -1)
        	ft_error_throw(ERROR_FORK);

        if (pid == 0)
        {
            if (i > 0 && dup2(pipes[i-1][0], STDIN_FILENO) == -1)
            	ft_error_throw(ERROR_DUP2);
            if (i < cmd_count - 1 && dup2(pipes[i][1], STDOUT_FILENO) == -1)
            	ft_error_throw(ERROR_DUP2);
            for (int j = 0; j < pipe_count; j++) {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }

            // Parse the command string into arguments
            args = ft_split_command(cmds[i]);
            if (!args || !args[0]) {
                fprintf(stderr, "Command parsing error\n");
                exit(EXIT_FAILURE);
            }

        	shell->current_cmds = args;

            // Create token for command execution
            token = ft_util_token_create(shell, args[0]);
            if (!token)
            	ft_error_throw(ERROR_TOKEN);
            token->type = TOKEN_CMD;
            ft_run_cmd(shell, token, env_list, args, pipe_count);
            free(token);
            ft_util_cmd_free(args);
            exit(shell->exit_status);
        }
    }
    for (i = 0; i < pipe_count; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }
    for (i = 0; i < cmd_count; i++) {
        int status;
        wait(&status);
    }
    return (true);
}

static char **ft_split_by_pipes(char *input)
{
    int i = 0;
    int start = 0;
    int count = 1;  // At least one command
    char **result;
    int in_quotes = 0;
    char quote_char = 0;

    // First count how many pipe-separated commands we have
    while (input[i]) {
        if (input[i] == '\'' || input[i] == '"') {
            if (!in_quotes) {
                in_quotes = 1;
                quote_char = input[i];
            } else if (input[i] == quote_char) {
                in_quotes = 0;
            }
        }

        if (input[i] == '|' && !in_quotes) {
            count++;
        }
        i++;
    }

    // Allocate memory for the result array
    result = (char **)malloc(sizeof(char *) * (count + 1));
    if (!result)
        return NULL;

    // Reset for the actual splitting
    i = 0;
    in_quotes = 0;
    count = 0;

    while (input[i]) {
        if (input[i] == '\'' || input[i] == '"') {
            if (!in_quotes) {
                in_quotes = 1;
                quote_char = input[i];
            } else if (input[i] == quote_char) {
                in_quotes = 0;
            }
        }

        if (input[i] == '|' && !in_quotes) {
            // Found a pipe outside quotes - split here
            result[count] = ft_strndup(input + start, i - start);
            if (!result[count]) {
                // Free allocated memory on error
                while (count > 0) {
                    free(result[--count]);
                }
                free(result);
                return NULL;
            }

            // Trim the result
            char *trimmed = ft_strtrim(result[count], " \t\n\r");
            free(result[count]);
            result[count] = trimmed;

            count++;
            start = i + 1;  // Start after the pipe
        }
        i++;
    }

    // Add the last part
    result[count] = ft_strndup(input + start, i - start);
    if (!result[count]) {
        // Free allocated memory on error
        while (count > 0) {
            free(result[--count]);
        }
        free(result);
        return NULL;
    }

    // Trim the last result
    char *trimmed = ft_strtrim(result[count], " \t\n\r");
    free(result[count]);
    result[count] = trimmed;

    // NULL-terminate the array
    result[count + 1] = NULL;

    return result;
}

static t_bool ft_parse_handle_process(t_shell *shell, t_parse *parse,
		t_env_list *env_list, char *str)
{
	char **cmd;
	int pipe_count;

	// Print raw command before splitting
	printf("Raw command before splitting: '%s'\n", str);
	printf("Pipe count before splitting: %d\n", parse->pipe);
	fflush(stdout);

	// Save the pipe count for later use
	pipe_count = parse->pipe;

	// Use our new function to properly split at pipes
	cmd = ft_split_by_pipes(str);
	if (cmd == NULL)
		return (false);

	// Print split commands
	printf("Split commands with new function:\n");
	for (int i = 0; cmd[i]; i++) {
		printf("  cmd[%d]: '%s'\n", i, cmd[i]);
	}
	fflush(stdout);

	// Only update begin_str (starting position for next command)
	parse->begin_str = parse->i + 1;

	if (parse->flag == true) {
		ft_parse_handle_exit(cmd, shell, true);
		return (true);
	}

	// If we have pipes, handle them specially
	if (pipe_count > 0) {
		printf("Handling piped command with %d pipes\n", pipe_count);
		fflush(stdout);
		if (ft_handle_piped_commands(shell, cmd, env_list, pipe_count) == false)
			return (ft_parse_handle_exit(cmd, shell, false));
	} else {
		// Normal command (no pipes)
		if (ft_util_token_process(shell, cmd, env_list) == false)
			return (ft_parse_handle_exit(cmd, shell, false));
	}
	parse->pipe = 0;

	return (ft_parse_handle_exit(cmd, shell, true));
}

t_bool	ft_parse_handle(t_shell *shell, t_env_list *env_list, char *str)
{
	t_parse	data;

	data = ft_init_parse_data();
	while (str[data.i])
	{
		ft_util_quote_status(&data.quotes, str[data.i]);
		if (str[data.i] == '\0' || (str[data.i] == ';'
				&& ft_util_quote_is_outside(&data.quotes) == TRUE)
			|| str[data.i + 1] == '\0')
		{
			data.flag = FALSE;
			if (ft_parse_handle_process(shell, &data, env_list, str) == FALSE)
				return (FALSE);
		}
		if (str[data.i] == '|'
			&& ft_util_quote_is_outside(&data.quotes) == TRUE)
			data.pipe++;
		if (str[data.i] == '\\' && data.quotes.two == TRUE)
			data.i += 2;
		else if (str[data.i] != '\0')
			data.i++;
	}
	return (TRUE);
}
