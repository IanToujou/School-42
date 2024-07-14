/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printablec.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:04:56 by ibour             #+#    #+#             */
/*   Updated: 2024/07/14 14:04:57 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

bool	is_char_printable(char c)
{
    return (c >= 32 && c != 127);
}

void ft_putstr_non_printable(char* str)
{
    char    c;
    int     i;

    i = 0;
    while(true)
    {
        c = str[i];
        if(c == '\0')
        {
            break ;
        }
        if(is_char_printable(c))
        {
            ft_putchar(c);
        }
        else
        {
            ft_putchar('\\');
            ft_putchar("0123456789abcdef"[i / 16]);
            ft_putchar("0123456789abcdef"[i % 16]);
        }
        i++;
    }
}

int main(int argc, char** argv)
{
    printf("Testing string: %s\n", argv[1]);
    ft_putstr_non_printable(argv[1]);
}
