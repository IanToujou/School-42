/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:28:30 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 14:52:38 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static const char	*ft_util_prompt_one(void)
{
	return (
		COLOR_RESET "┌──(" COLOR_PINK "≽^•w•^≼"
		COLOR_RESET " | " COLOR_PINK
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

static char	*build_prompt_parts(t_env_list *env_list)
{
	char	*one;
	char	*two;
	char	*three;
	char	*cwd;
	char	*temp;

	if (ft_util_env_get(&env_list, "USER"))
		one = ft_strjoin(ft_util_prompt_one(),
				ft_util_env_get(&env_list, "USER"));
	else
		one = ft_strjoin(ft_util_prompt_one(), "nya");
	if (!one)
		ft_error_throw(ERROR_MALLOC);
	two = ft_strjoin(one, ft_util_prompt_two());
	free(one);
	if (!two)
		ft_error_throw(ERROR_MALLOC);
	cwd = ft_cmd_pwd_get();
	three = ft_strjoin(two, cwd);
	free(two);
	if (!three)
		ft_error_throw(ERROR_MALLOC);
	temp = three;
	free(cwd);
	return (temp);
}

char	*ft_util_prompt(t_env_list *env_list)
{
	char	*prompt_body;
	char	*result;

	prompt_body = build_prompt_parts(env_list);
	result = ft_strjoin(prompt_body, ft_util_prompt_three());
	free(prompt_body);
	if (!result)
		ft_error_throw(ERROR_MALLOC);
	return (result);
}
