/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:01:03 by ibour             #+#    #+#             */
/*   Updated: 2024/07/15 15:01:03 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int		i;
	char	*result;

	result = dest;
	i = 0;
	while (*result != '\0')
	{
		result++;
	}
	while (*src != '\0' && i < nb)
	{
		*result = *(unsigned char *) src;
		result++;
		src++;
		i++;
	}
	*result = '\0';
	return (dest);
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
    printf("Result: %s\n", ft_strncat(argv[1], argv[2], 5));
}*/
