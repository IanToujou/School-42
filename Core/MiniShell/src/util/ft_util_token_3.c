/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_token_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:04:42 by ibour             #+#    #+#             */
/*   Updated: 2025/05/15 09:52:33 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_util_token_check_cmd(const char *str)
{
	if (ft_strncmp(str, "<<", ft_strlen("<<") + 1) == 0)
		return (TOKEN_DOBINP);
	if (ft_strncmp(str, "<", ft_strlen("<") + 1) == 0)
		return (TOKEN_INPUT);
	if (ft_strncmp(str, ">>", ft_strlen(">>") + 1) == 0)
		return (TOKEN_APPEND);
	if (ft_strncmp(str, ">", ft_strlen(">") + 1) == 0)
		return (TOKEN_TRUNC);
	if (ft_strncmp(str, "|", ft_strlen("|") + 1) == 0)
		return (TOKEN_PIPE);
	return (REDIRECT_EMPTY);
}

static void	ft_util_token_init(t_token *temp, const int i)
{
	if (i == 0 && ft_util_token_check_cmd(temp->str) == REDIRECT_EMPTY)
		temp->type = TOKEN_CMD;
	else if (i == 0 && ft_util_token_check_cmd(temp->str) != REDIRECT_EMPTY)
		temp->type = ft_util_token_check_cmd(temp->str);
	else if (ft_util_token_check_cmd(temp->prev->str) == TOKEN_PIPE
		&& ft_util_token_check_cmd(temp->str) == REDIRECT_EMPTY)
		temp->type = TOKEN_CMD;
	else if (ft_util_token_check_cmd(temp->str) != REDIRECT_EMPTY)
		temp->type = ft_util_token_check_cmd(temp->str);
	else
		temp->type = TOKEN_ARG;
}

char	**ft_util_token_free_cmds(char **cmds)
{
	int			i;

	i = -1;
	if (cmds)
	{
		while (cmds[++i])
			free(cmds[i]);
		free(cmds);
		cmds = NULL;
	}
	return (cmds);
}

t_token	*ft_util_token_to_struct(char **cmds)
{
	int		i;
	t_token	*head;
	t_token	*temp;

	i = -1;
	head = NULL;
	while (cmds[++i])
	{
		temp = ft_util_token_create(cmds[i]);
		if (temp == NULL)
		{
			ft_util_token_free(head);
			ft_error_throw(ERROR_MALLOC);
		}
		ft_util_token_add_back(&head, temp);
		if (temp->str)
			ft_util_token_init(temp, i);
	}
	return head;
}