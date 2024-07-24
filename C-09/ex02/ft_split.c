/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:03:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 07:03:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool    char_in_str(char c, char *str) {
    while (true) {
        if (*str == '\0')
            return (c == '\0');
        if (*str == c)
            return true;
        str++;
    }
    return (false);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int	index;

    index = 0;
    while (src[index] != '\0' && index < n)
    {
        dest[index] = src[index];
        index++;
    }
    while (index < n)
    {
        dest[index] = '\0';
        index++;
    }
    return (dest);
}

int     add_str_part(char **entry, char *prev, int size, char *charset) {
    if (char_in_str(prev[0], charset)) {
        prev++;
        size--;
    }
    *entry = (char*) malloc((size + 3) * sizeof(char));
    ft_strncpy(*entry, prev, size);
    (*entry)[size] = '\0';
    (*entry)[size + 1] = '\0';
    return (1);
}

int count_occ(char *str, char *charset) {
    int     count;
    char    *prev;
    char    *next;

    count = 0;
    prev = str;
    next = str;
    while (true) {
        if (char_in_str(*str, charset))
            next = str;
        if ((next - prev) > 1)
            count++;
        if (*str == '\0')
            break;
        prev = next;
        str++;
    }
    return (count);
}

char    **ft_split(char *str, char *charset)
{
    int     i;
    int     size;
    char    **array;
    char    *next;
    char    *prev;

    i = 0;
    next = str;
    prev = str;
    size = next - prev;
    array = (char**) malloc((count_occ(str, charset) + 1) * sizeof(char*));
    while (true) {
        if (char_in_str(*str, charset))
            next = str;
        if (size > 1)
            i += add_str_part(&array[i], prev, size, charset);
        if (*str == '\0')
            break;
        prev = next;
        str++;
    }
    array[i] = 0;
    return (array);
}

int		main(int argc, char **argv)
{
    int		index;
    char	**split;

    split = ft_split(argv[1], argv[2]);
    index = 0;
    printf("before loop");
    while (split[index])
    {
        printf("loop");
        printf("array[%d] = %s\n", index, split[index]);
        index++;
    }
    free(split);
}
