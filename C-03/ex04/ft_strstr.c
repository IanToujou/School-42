/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:01:14 by ibour             #+#    #+#             */
/*   Updated: 2024/07/15 15:01:15 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*a;
	char	*b;

	if (*to_find == '\0')
	{
		return (str);
	}
	a = str;
	b = to_find;
	while (true)
	{
		if (*b == '\0')
			return (a - (b - to_find));
		if (*a == *b)
			b++;
		else
			b = to_find;
		if (*a == '\0')
			break ;
		a++;
	}
	return (0);
}

/*int    main(int argc, char** argv)
{
    if (argv[1] == (void *)0 || argv[2] == (void *)0)
    {
        printf("You need to input at least two strings!\n");
        return 0;
    }
    printf("Input 1: %s\n", argv[1]);
    printf("Input 2: %s\n", argv[2]);
    printf("Result: %s\n", ft_strstr(argv[1], argv[2]));
}*/
