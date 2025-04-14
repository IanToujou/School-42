/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:01:48 by ibour             #+#    #+#             */
/*   Updated: 2025/04/14 13:36:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Parses the environment variables, essentially by splitting
 * them on the '=' sign. For instance, "KEY"="VALUE" will be
 * saved inside the list as a variable with the key "KEY" and
 * value "VALUE".
 *
 * @param env_list The environment variables struct.
 * @param env The environment passed from main.
 */
void	ft_parse_env(t_env_list **env_list, char **env)
{
	int	i;

	printf("parse_env\n"); fflush(stdout);

	if (!env) {
		printf("balls\n"); fflush(stdout);
		return;
	}
	i = 0;
	while (env[i]) {
		printf("%s\n", env[i]);
		ft_util_env_var_add(env_list, env[i++]);
	}
}
