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

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int	ft_tl(char **strs, int size, int sep_length)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (i < size)
	{
		length += ft_sl(strs[i]);
		length += sep_length;
		i++;
	}
	length -= sep_length;
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*head;
	char	*str;

	if (size == 0)
		return (malloc(sizeof(char)));
	str = (char *)malloc((ft_tl(strs, size, ft_sl(sep)) + 1) * sizeof(char));
	if (!str)
		return (0);
	head = str;
	i = 0;
	while (i < size)
	{
		ft_strcpy(head, strs[i]);
		head += ft_sl(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(head, sep);
			head += ft_sl(sep);
		}
		i++;
	}
	*head = '\0';
	return (str);
}

/*#include <stdio.h>
int		main(void)
{
    int		index;
    char	**strs;
    char	*separator;
    char	*result;

    strs = (char**) malloc(4 * sizeof(strs));
    strs[0] = "lol";
    strs[1] = "1234";
    separator = "-";
    index = 0;

    while (index < 4)
    {
        result = ft_strjoin(index, strs, separator);
        printf("Result (Size %d) = %s\n", index, result);
        free(result);
        index++;
    }
}*/
