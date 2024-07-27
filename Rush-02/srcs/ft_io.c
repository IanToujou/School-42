/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 19:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_io.h"

void    ft_putchar(int out, char c) {
    write(out, &c, 1);
}

void    ft_putstr(int out, char *str) {
    int index;

    index = 0;
    while(str[index] != '\0') {
        ft_putchar(out, str[index]);
        index++;
    }
}