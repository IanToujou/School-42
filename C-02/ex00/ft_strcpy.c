/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strlen.c >                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 07:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/07/11 07:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	index;
	
	printf("Dest val is: %s \n", dest);
	printf("Src val is: %s \n", src);
	
	printf("e");
	
	index = 0;
	
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int main(void) {
	char	*str = "Test";
	char	*str2 = "a";
	ft_strcpy(str2, str);
	printf("%s", str);
}
