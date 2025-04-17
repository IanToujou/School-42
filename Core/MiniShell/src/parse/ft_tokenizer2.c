/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:29:13 by ibour             #+#    #+#             */
/*   Updated: 2025/04/17 10:02:27 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * Counts the number of words in a string
 * Words are separated by spaces or tabs
 * Used for memory allocation in splitting logic
 */
int	count_words(const char *str)
{
	int		count;
	bool	in_word;

	count = 0;
	in_word = false;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
		{
			in_word = false;
		}
		else if (!in_word)
		{
			in_word = true;
			count++;
		}
		str++;
	}
	return (count);
}

/*
 * Extracts the next word from a string and advances the pointer
 * Skips leading whitespace and returns a newly allocated word
 * Returns NULL on allocation failure
 */
char	*get_next_word(const char **str)
{
	const char	*start;
	char		*word;
	int			len;

	len = 0;
	while (**str == ' ' || **str == '\t')
		(*str)++;
	start = *str;
	while (**str && **str != ' ' && **str != '\t')
	{
		(*str)++;
		len++;
	}
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	strncpy(word, start, len);
	word[len] = '\0';
	return (word);
}

/*
 * Splits a shell input string by whitespace into words
 * Ignores multiple spaces/tabs and trims them automatically
 * Returns a NULL-terminated array of strings or NULL on failure
 */
char	**ft_split_shell(const char *str)
{
	int		word_count;
	char	**split;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	word_count = count_words(str);
	split = malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (i < word_count)
	{
		split[i] = get_next_word(&str);
		if (!split[i])
		{
			while (i > 0)
				free(split[--i]);
			free(split);
			return (NULL);
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}
