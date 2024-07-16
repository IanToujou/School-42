/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:01:25 by ibour             #+#    #+#             */
/*   Updated: 2024/07/15 15:01:26 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_str_length_fast(char *dest)
{
	unsigned int	count;

	count = 0;
	while (dest[count] != '\0')
		count++;
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*s;
	char			*src_start;
	unsigned int	dst_length;
	unsigned int	remaining;

	s = dest;
	src_start = src;
	remaining = size;
	while (remaining-- != 0 && *s != '\0')
		s++;
	dst_length = s - dest;
	remaining = size - dst_length;
	if (remaining == 0)
		return (dst_length + ft_str_length_fast(src));
	while (*src != '\0')
	{
		if (remaining > 1)
		{
			*s++ = *src;
			remaining--;
		}
		src++;
	}
	*s = '\0';
	return (dst_length + (src - src_start));
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
    printf("Result: %d\n", ft_strlcat(argv[1], argv[2], 5));
}*/
