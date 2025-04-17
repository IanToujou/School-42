/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:28:29 by ibour             #+#    #+#             */
/*   Updated: 2025/04/17 10:02:40 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * Adds a token to the end of a doubly linked token list
 * Updates both next and prev pointers accordingly
 * Does nothing if the new token is NULL
 */
void	ft_token_add_back(t_token **lst, t_token *new)
{
	t_token	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

/*
 * Frees all memory used by a linked list of tokens
 * Frees both the token structure and its value string
 */
void	ft_free_tokens(t_token *lst)
{
	t_token	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->value);
		free(lst);
		lst = tmp;
	}
}

/*
 * Checks if a character at given position is within quotes
 * Handles both single and double quotes
 * Used to avoid expanding variables inside quotes
 */
bool	is_quoted(char *str, int pos)
{
	bool	single_quote;
	bool	double_quote;
	int		i;

	single_quote = false;
	double_quote = false;
	i = 0;
	while (i < pos)
	{
		if (str[i] == '\'' && !double_quote)
			single_quote = !single_quote;
		else if (str[i] == '"' && !single_quote)
			double_quote = !double_quote;
		i++;
	}
	return (single_quote || double_quote);
}

/*
 * Concatenates two strings and frees the first one
 * Returns a newly allocated string or NULL on failure
 * If first string is NULL, duplicates second
 */
char	*ft_strjoin_free(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (strdup(s2));
	if (!s2)
		return (s1);
	len1 = strlen(s1);
	len2 = strlen(s2);
	joined = malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	strcpy(joined, s1);
	strcpy(joined + len1, s2);
	free(s1);
	return (joined);
}

/*
 * Appends a single character to a string
 * Returns a newly allocated string with the character added
 * Original string is not freed
 */
char	*ft_strjoin_char(char *s, char c)
{
	size_t	len;
	char	*new_str;

	if (s)
		len = strlen(s);
	else
		len = 0;
	new_str = malloc(len + 2);
	if (!new_str)
		return (NULL);
	if (s)
		strcpy(new_str, s);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	return (new_str);
}
