/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:39:27 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 11:29:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void ft_run_cmd(t_shell *shell, t_token *token, t_env_list *env_list, char **args)
{
	printf("executing: %s with arguments: ", token->str);
	for (int i = 0; args[i]; i++) {
		printf("%s ", args[i]);
	}
	printf("\n");
	fflush(stdout);

	if (ft_run_defined_is_defined(token))
		ft_run_defined(shell, token, env_list, args);
	else
		ft_run_bin(shell, token, env_list);
}

