/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/30 13:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	*str_n_copy(char *dest, char *src, int n)
{
	int		index;

	index = 0;
	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

char	*extend_array(char *orig, char *n_cont, UINT old_len, UINT len)
{
	char	*dest;

	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	if (orig != NULL)
		str_n_copy(dest, orig, old_len);
	str_n_copy(dest + old_len, n_cont, len - old_len);
	if (orig != NULL)
		free(orig);
	return (dest);
}

t_bool	atoi_n_strict(char *str, UINT n, UINT *result)
{
	UINT	index;

	index = 0;
	*result = 0;
	while (index < n)
	{
		if ('0' <= str[index] && str[index] <= '9')
			*result = *result * 10 + str[index] - '0';
		else
			return (false);
		index++;
	}
	return (true);
}
