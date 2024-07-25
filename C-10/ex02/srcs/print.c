/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:13:09 by ibour             #+#    #+#             */
/*   Updated: 2024/07/25 15:13:10 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	print_file(int argc, char **args, int octet)
{
    int		i;
    int		j;
    int		size;

    i = 0;
    j = 0;
    while (args[++i] != 0)
        if ((size = ft_file_count(args[i])) == -1)
        {
            if (errno != 21)
                print_error(args, i);
        }
        else
        {
            if (argc > 4)
            {
                if (i != 1 && j != 0)
                    ft_putchar('\n', 1);
                ft_putstr_headfile(args[i]);
                j++;
            }
            ft_file_get(args[i], size, octet);
        }
}

void	print_error(char **args, int i)
{
    ft_putstr(basename(args[0]), 2);
    ft_putstr(": ", 2);
    ft_putstr(args[i], 2);
    ft_putstr(": ", 2);
    ft_putstr(strerror(errno), 2);
    ft_putchar('\n', 2);
}

void	print_illegal(char *name, char *obj)
{
    ft_putstr(basename(name), 2);
    ft_putstr(": illegal offset -- ", 2);
    ft_putstr(obj, 2);
    ft_putchar('\n', 2);
}

void	print_help(char *name)
{
    ft_putstr(basename(name), 2);
    ft_putstr(": option require an argument -- c\nusage: ", 2);
    ft_putstr(basename(name), 2);
    ft_putstr(" [-F | -f | -r] [-q] [-b # | -c # | -n #] [file ...]\n", 2);
}
