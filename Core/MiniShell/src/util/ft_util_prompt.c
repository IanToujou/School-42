/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:28:30 by ibour             #+#    #+#             */
/*   Updated: 2025/05/13 16:11:44 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static const char	*ft_util_prompt_one(void)
{
	return (
		COLOR_RESET "┌──(" COLOR_PINK "≽^•w•^≼" COLOR_RESET " | " COLOR_PINK
	);
}

static const char	*ft_util_prompt_two(void)
{
	return (
		COLOR_RESET ")──[" COLOR_CYAN
	);
}

static const char	*ft_util_prompt_three(void)
{
	return (
		COLOR_RESET "]\n"
		"└─$ " COLOR_RESET
	);
}

char	*ft_util_prompt(t_env_list *env_list)
{
	char	*result;
	char	*cwd;
	char	*one;
	char	*two;
	char	*three;

	if (ft_util_env_get(&env_list, "USER"))
		one = ft_strjoin(ft_util_prompt_one(), ft_util_env_get(&env_list, "USER"));
	else
		one = ft_strjoin(ft_util_prompt_one(), "nya");
	if (one == NULL)
		ft_error_throw(ERROR_MALLOC);
	two = ft_strjoin(one, ft_util_prompt_two());
	free(one);
	if (two == NULL)
		ft_error_throw(ERROR_MALLOC);
	cwd = ft_cmd_pwd_get();
	three = ft_strjoin(two, cwd);
	free(two);
	if (three == NULL)
		ft_error_throw(ERROR_MALLOC);
	result = ft_strjoin(three, ft_util_prompt_three());
	free(three);
	free(cwd);
	return (result);
}
