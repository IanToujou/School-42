/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:17:38 by ibour             #+#    #+#             */
/*   Updated: 2024/07/21 17:17:39 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_sl(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	ft_tl(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_sl(strs[i]);
		i++;
	}
	total_len += ft_sl(sep) * (size - 1);
	return (total_len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	c;
	int	d;

	c = 0;
	d = 0;
	while (dest[c] != '\0')
		c++;
	while (src[d] != '\0')
	{
		dest[c] = src[d];
		c++;
		d++;
	}
	dest[c] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	int		i;
	char	*ret;

	if (size == 0)
	{
		ret = malloc(sizeof(char));
		ret[0] = '\0';
		return (ret);
	}
	total_len = ft_tl(size, strs, sep);
	ret = malloc(sizeof(char) * (total_len + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	ret[0] = '\0';
	while (i < size)
	{
		ft_strcat(ret, strs[i]);
		if (i < size - 1)
			ft_strcat(ret, sep);
		i++;
	}
	return (ret);
}

/*#include <stdio.h>
int main(void)
{
	char *strs[4] = {"Hello", "World", "!", "!"};
	char *sep = " - ";
	char *ret;

	ret = ft_strjoin(4, strs, sep);
	printf("%s\n", ret);
	free(ret);
	return (0);
}*/
