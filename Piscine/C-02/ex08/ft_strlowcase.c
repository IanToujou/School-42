/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:04:04 by ibour             #+#    #+#             */
/*   Updated: 2024/07/14 14:04:04 by ibour            ###   ########.fr       */
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

/*int main(int argc, char** argv)
{
    printf("Input string: %s\n", argv[1]);
    printf("Result: %s\n", ft_strlowcase(argv[1]));
}*/
