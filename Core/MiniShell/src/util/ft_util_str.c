/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:02:13 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 17:08:55 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_bool	ft_util_str_strchr(const char *s, const int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (true);
		i++;
	}
	if (c == '\0')
		return (true);
	return (false);
}

static size_t	ft_util_str_trim_all(const char *str, size_t size,
		size_t *begin, size_t *end)
{
	while (*begin < size && ft_isblank(str[*begin]))
		(*begin)++;
	if (*begin == size)
		return (0);
	while (*end > *begin && ft_isblank(str[*end]))
		(*end)--;
	return (*end - *begin + 1);
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
	size_t	new_size;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (size == 0)
		return (ft_strdup(""));
	begin = 0;
	end = size - 1;
	new_size = ft_util_str_trim_all(str, size, &begin, &end);
	if (new_size == 0)
		return (ft_strdup(""));
	return (ft_substr(str, begin, new_size));
}

char	*ft_util_str_tolower(const char *str)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * 4);
	if (result == NULL)
		ft_error_throw(ERROR_MALLOC);
	result[3] = '\0';
	i = 0;
	while (*str)
	{
		if (ft_isalpha(*str))
			result[i] = ft_tolower(*str);
		else
			result[i] = *str;
		i++;
		str++;
	}
	return (result);
}
