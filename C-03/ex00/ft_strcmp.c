/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:59:59 by ibour             #+#    #+#             */
/*   Updated: 2024/07/15 15:00:00 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char* s1, char* s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}

int	main(int argc, char** argv)
{
	if(argv[1] == (void *)0 || argv[2] == (void *)0)
	{
		printf("You need to input at least two strings!");
		return 0;
	}
	printf("Input 1: %s", argv[1]);
	printf("Input 2: %s", argv[2]);
	printf("Result: %d", ft_strcmp(argv[1], argv[2]));
}