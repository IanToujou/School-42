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

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}

/*int	main(int argc, char** argv)
{
	if (argv[1] == (void *)0 || argv[2] == (void *)0)
	{
		printf("You need to input at least two strings!\n");
		return 0;
	}
	printf("Input 1: %s\n", argv[1]);
	printf("Input 2: %s\n", argv[2]);
	printf("Result: %d\n", ft_strcmp(argv[1], argv[2]));
}*/
