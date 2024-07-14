/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:04:38 by ibour             #+#    #+#             */
/*   Updated: 2024/07/14 14:04:39 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int count;
    unsigned int index;

    index = 0;
    count = 0;

    while (src[count] != '\0')
    {
        count++;
    }
    if (size != 0)
    {
        while (src[index] != '\0' && index < (size - 1))
        {
            dest[index] = src[index];
            index++;
        }
        dest[index] = '\0';
    }
    return (count);

}

int main(void) {
    char *src;
    char dest[0]; // char[] is read-write and *char is read only.

    src = "Hello World";
    printf("base: %s\n", src);
    printf("before copy: %s\n", dest);
    ft_strlcpy(dest, src, 12);
    printf("after copy: %s\n", dest);
}
