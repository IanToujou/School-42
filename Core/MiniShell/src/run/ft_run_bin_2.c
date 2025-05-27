/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_bin_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:11:01 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 20:13:01 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_run_bin_piped_prepare_existing(const t_shell *shell,
		char ***args, int *i)
{
	*args = shell->current_cmds;
	*i = 0;
	while ((*args)[*i])
		(*i)++;
}

char	**ft_run_bin_piped_allocate(const int size)
{
	char	**args;

	args = (char **) malloc(sizeof(char *) * (size + 1));
	if (args == NULL)
		ft_error_throw(ERROR_MALLOC);
	return (args);
}

void	ft_run_bin_piped_populate(char **args,
		const t_token *current, const int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		args[i] = ft_strtrim(current->str, " ");
		if (args[i] == NULL)
			ft_error_throw(ERROR_MALLOC);
		current = current->next;
	}
	args[size] = NULL;
}

char	**ft_run_bin_piped_args(const t_token *token)
{
	int		size;
	char	**args;

	size = ft_run_bin_token_length(token->next);
	args = ft_run_bin_piped_allocate(size);
	ft_run_bin_piped_populate(args, token, size);
	return (args);
}
