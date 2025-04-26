/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_nya.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:36:12 by ibour             #+#    #+#             */
/*   Updated: 2025/04/26 18:36:56 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_cmd_nya(t_shell *shell, t_env_list **env_list, t_token *token)
{
	(void)shell;
	(void)env_list;
	(void)token;
	ft_putstr_fd("Meow\n", STDERR_FILENO);
}
