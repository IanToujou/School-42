/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:40:54 by mpoesy            #+#    #+#             */
/*   Updated: 2024/10/25 10:02:04 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numtotrimstart(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		flag = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	numtotrimend(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = 0;
	while ((ft_strlen(s1) - i) > 0)
	{
		j = 0;
		flag = 0;
		while (j < ft_strlen(set))
		{
			if (s1[ft_strlen(s1) - i - 1] == set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			return (i);
		i++;
	}
	return (i);
}

static char	*trim_malloc(size_t len)
{
	char	*ptr;

	ptr = malloc(len + 1);
	if (ptr)
		ptr[len] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ptr;

	if (!s1)
		return (NULL);
	i = numtotrimstart(s1, set);
	j = numtotrimend(s1, set);
	if (i == ft_strlen(s1))
		return (trim_malloc(0));
	ptr = trim_malloc(ft_strlen(s1) - i - j);
	if (ptr == NULL)
		return (NULL);
	k = 0;
	while (i + k < ft_strlen(s1) - j)
	{
		ptr[k] = s1[i + k];
		k++;
	}
	ptr[k] = '\0';
	return (ptr);
}
/*
#include <stdio.h>

int	main(void) {
	const char *testString = "   \t  \n\n \t\t  \n\n\n
	Hello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
	const char *set = " \n\t";

	// Test ft_strtrim function
	char *trimmedString = ft_strtrim(testString, set);

	// Print results
	if (trimmedString != NULL) {
		printf("Original string: '%s'\n", testString);
		printf("Trimmed string: '%s'\n", trimmedString);
		free(trimmedString); // Don't forget to free allocated memory
	} else {
		printf("Memory allocation failed!\n");
	}

	return (0);
}*/
