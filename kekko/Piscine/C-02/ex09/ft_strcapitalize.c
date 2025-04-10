/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:04:19 by ibour             #+#    #+#             */
/*   Updated: 2024/07/14 14:04:19 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

void	ft_transform_char(char *c, bool to_upper)
{
	if (!to_upper)
	{
		if (*c >= 'A' && *c <= 'Z')
		{
			*c = *c + 32;
		}
	}
	else
	{
		if (*c >= 'a' && *c <= 'z')
		{
			*c = *c - 32;
		}
	}
}

bool	is_char_alpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

bool	is_char_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

void	ft_strcapitalize_delegate(char *curr, bool *in_word, bool *skip_word)
{
	bool	first_letter;

	first_letter = false;
	if (!*in_word)
	{
		if (is_char_numeric(*curr))
			*skip_word = true;
		else if (is_char_alpha(*curr) && !*skip_word)
		{
			*in_word = true;
			first_letter = true;
		}
	}
	ft_transform_char(curr, false);
	if (*in_word)
		ft_transform_char(curr, first_letter);
}

char	*ft_strcapitalize(char *str)
{
	int		index;
	char	*curr;
	bool	in_word;
	bool	skip_word;

	index = 0;
	in_word = false;
	skip_word = false;
	while (true)
	{
		curr = &str[index];
		if (*curr == '\0')
			break ;
		ft_strcapitalize_delegate(curr, &in_word, &skip_word);
		if (!(is_char_alpha(*curr) || is_char_numeric(*curr)))
		{
			in_word = false;
			skip_word = false;
		}
		index++;
	}
	return (str);
}

/*#include <stdio.h>
int main(int argc, char** argv)
{
    printf("Input string: %s\n", argv[1]);
    printf("Result: %s\n", ft_strcapitalize(argv[1]));
}
*/
