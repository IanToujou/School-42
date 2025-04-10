/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:03:50 by ibour             #+#    #+#             */
/*   Updated: 2024/07/14 14:03:50 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

char	*ft_strupcase(char *str)
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
		if (c >= 'a' && c <= 'z')
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
    printf("Result: %s\n", ft_strupcase(argv[1]));
}*/
