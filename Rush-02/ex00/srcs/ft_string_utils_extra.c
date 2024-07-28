/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils_extra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 19:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string_utils.h"

int	ft_total_length(char **strings, int size, int sep_length)
{
	int	final_length;
	int	index;

	final_length = 0;
	index = 0;
	while (index < size)
	{
		final_length += ft_str_length(strings[index]);
		final_length += sep_length;
		index++;
	}
	final_length -= sep_length;
	return (final_length);
}

char	*ft_str_join(int size, char **strs, char *sep)
{
	int		full_length;
	int		index;
	char	*read_head;
	char	*string;

	if (size == 0)
		return (malloc(sizeof(char)));
	full_length = ft_total_length(strs, size, ft_str_length(sep));
	string = (char *)malloc((full_length + 1) * sizeof(char));
	if (string == NULL)
		return (0);
	read_head = string;
	index = 0;
	while (index < size)
	{
		ft_str_copy(read_head, strs[index]);
		read_head += ft_str_length(strs[index]);
		if (index < size - 1)
		{
			ft_str_copy(read_head, sep);
			read_head += ft_str_length(sep);
		}
		index++;
	}
	*read_head = '\0';
	return (string);
}

int	ft_split_whitespace_count_word(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (ft_is_whitespace(*str))
			str++;
		if (*str == '\0')
			break ;
		while (!ft_is_whitespace(*str) && *str != '\0')
			str++;
		count++;
	}
	return (count);
}

char	**ft_split_whitespace(char *str)
{
	int		index;
	int		word_count;
	char	*word_start;
	char	**array;

	word_count = ft_split_whitespace_count_word(str);
	array = malloc((word_count + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	index = 0;
	while (*str)
	{
		while (ft_is_whitespace(*str))
			str++;
		if (*str == '\0')
			break ;
		word_start = str;
		while (!ft_is_whitespace(*str) && *str != '\0')
			str++;
		array[index] = ft_str_n_duplicate(word_start, str - word_start);
		index++;
	}
	array[index] = 0;
	return (array);
}
