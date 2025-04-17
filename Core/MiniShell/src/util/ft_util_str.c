/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:02:13 by ibour             #+#    #+#             */
/*   Updated: 2025/04/17 20:13:09 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_util_str_trim_all(const char *str, size_t size, size_t *begin, size_t *end)
{
	while (ft_isblank(str[*begin]))
	{
		(*begin)++;
		size--;
	}
	while (ft_isblank(str[*end]))
	{
		(*end)--;
		size--;
	}
	return (size);
}

t_bool	ft_util_str_tab_skip(const char *str)
{
	int		i;
	size_t	size;

	i = -1;
	size = ft_strlen(str);
	while (ft_isblank(str[++i]))
		size--;
	if (size == 0)
		return (TRUE);
	return (FALSE);
}

char	*ft_util_str_tab_trim(const char *str)
{
	size_t	begin;
	size_t	end;
	size_t	size;

	begin = 0;
	end = ft_strlen(str) - 1;
	size = ft_strlen(str);
	if (size == 0)
		return (ft_strdup(""));
	if (ft_util_str_trim_all(str, size, &begin, &end) <= 0)
		return (ft_strdup(""));
	return (ft_substr(str, begin, size));
}