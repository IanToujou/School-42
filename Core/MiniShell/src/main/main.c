/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:48:58 by ibour             #+#    #+#             */
/*   Updated: 2025/03/26 17:03:55 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Bro this is the main function, what do you expect it to do?
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @param env The environment variables.
 * @return A specified status code related to the program.
 */
int	main(const int argc, char **argv, char **env)
{
	t_shell		shell;
	t_env_list	*env_list;
	char		*line;

	(void) argc;
	(void) argv;
	ft_util_banner();
	env_list = NULL;
	if (!ft_init_env(&shell, env_list, env))
		ft_error_throw(ERROR_INIT_ENV);
	if (!ft_init_temp(&shell))
		ft_error_throw(ERROR_INIT_TEMP);
	if (!ft_init_std(&shell))
		ft_error_throw(ERROR_INIT_STD);
	if (!ft_exit_std(&shell))
		ft_error_throw(ERROR_EXIT_STD);
	ft_exit_env(&env_list);
	
	while(0xCE77)
	{
		line = ft_read_line();
		printf("%s\n", line);
	}
	
	return (shell.exit_status);
}

/**
 * Subjected to change (A LOT), it is not even his final form yet
 * & discuss where to put it also.
 * But it feels more like shell now amirite???
 */
char	*ft_read_line(void)
{
	char *buf;
	size_t	bufsize;
	char	cwd[BUFSIZ];

	buf = NULL;
	getcwd(cwd, sizeof(cwd));
	printf("🐱%s🐱 > ", cwd);
	if (getline(&buf, &bufsize, stdin) == -1)
	{
		buf = NULL;
		if (feof(stdin))
			printf("🐱[EOF]🐱 > ");
		else
			ft_error_throw(ERROR_EXIT_STD);
	}
	return (buf);
}
