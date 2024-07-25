/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:13:23 by ibour             #+#    #+#             */
/*   Updated: 2024/07/25 15:13:23 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*ft_strdup(char *src)
{
    char	*dest;
    int		i;

    i = 0;
    while (src[i])
        i++;
    dest = malloc(sizeof(src) * (i + 1));
    if (dest == NULL)
        return (NULL);
    i = 0;
    if (dest == NULL)
        return (0);
    else
    {
        while (src[i])
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
        return (dest);
    }
}
