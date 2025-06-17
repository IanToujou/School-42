/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:40:54 by mpoesy            #+#    #+#             */
/*   Updated: 2024/10/25 12:08:43 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
//#include <stdlib.h>

static char	*copy_word(const char *start, int len)
{
	int		i;
	char	*word;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	fill_result(char **result, const char *s, char c)
{
	int			i;
	const char	*word_start = s;
	int			len;

	i = 0;
	while (*s)
	{
		while (*s == c)
		{
			word_start++;
			s++;
		}
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len > 0)
			result[i++] = copy_word(word_start, len);
		s += len;
		word_start = s;
	}
	result[i] = NULL;
}

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**result;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	fill_result(result, s, c);
	return (result);
}
/*
int	main(void)
{
	char	*str;
	char	delimiter;
	char	**result;
	int		i;

	str = "Hello,world,this,is,a,test";
	delimiter = ',';
	// Call the split function
	result = ft_split(str, delimiter);
	// Check if the result is NULL (in case of memory allocation failure)
	if (result == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	// Print the resulting array
	printf("Result of ft_split:\n");
	for (i = 0; result[i] != NULL; i++)
	{
		printf("result[%d]: %s\n", i, result[i]);
		free(result[i]); // Free each allocated string
	}
	free(result); // Free the array of pointers
	return (0);
}*/
