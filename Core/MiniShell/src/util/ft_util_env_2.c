/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_env_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:13:07 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 17:13:21 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_util_env_free(t_env_list	*env_list)
{
	if (!env_list)
		return ;
	if (env_list->current)
	{
		free(env_list->current->key);
		free(env_list->current->value);
		free(env_list->current);
	}
	free(env_list);
}
