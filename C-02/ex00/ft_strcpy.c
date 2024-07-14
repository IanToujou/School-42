/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strcpy.c >                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 07:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/07/11 07:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	index;
	
	index = 0;
	
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

/*int main(void) {
	char *src;
	char dest[0]; // char[] is read-write and *char is read only.

	src = "Hello World";
	printf("base: %s\n", src);
	printf("before copy: %s\n", dest);
	ft_strcpy(dest, src);
	printf("after copy: %s\n", dest);
}*/
