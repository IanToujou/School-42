/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_cmd_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:45:02 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 17:09:50 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_util_cmd_free(char **cmds)
{
	int	i;

	i = -1;
	if (cmds != NULL)
	{
		while (cmds[++i])
			free(cmds[i]);
		free(cmds);
	}
	return (NULL);
}
