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

char	*ft_strlowcase(char *str)
{
	int		i;
	char	c;
	char	d;

	i = 0;
	while (true)
	{
		c = str[i];
		if (c == '\0')
		{
			break ;
		}
		if (c >= 'A' && c <= 'Z')
		{
			d = c + 32;
			str[i] = d;
		}
		i++;
	}
	return (str);
}

bool	ft_check_capitalizable(char *str, char c, int i)
{
	if ((str[i -1] == '\0' || str[i -1] == ' ') && (c >= 'a' && c <= 'z'))
	{
		return (true);
	}
	if ((str[i -1] == '+' || str[i -1] == '-') && (c >= 'a' && c <= 'z'))
	{
		return (true);
	}
	return (false);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	c;
	char	d;

	str = ft_strlowcase(str);
	i = 0;
	while (true)
	{
		c = str[i];
		if (c == '\0')
		{
			break ;
		}
		if (ft_check_capitalizable(str, c, i))
		{
			d = c - 32;
			str[i] = d;
		}
		i++;
	}
	return (str);
}

/*int main(int argc, char** argv)
{
    printf("Input string: %s\n", argv[1]);
    printf("Result: %s\n", ft_strcapitalize(argv[1]));
}*/
