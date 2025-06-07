/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_bin_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:40:00 by ibour             #+#    #+#             */
/*   Updated: 2025/04/30 19:40:16 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_util_bin_free_paths(char **paths, char *cmd_with_slash)
{
	int	i;

	i = -1;
	while (paths && paths[++i])
		free(paths[i]);
	free(paths);
	free(cmd_with_slash);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}
