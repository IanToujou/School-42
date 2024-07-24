/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   without_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:39:17 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 18:39:44 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "../includes/ft.h"

void    without_args(char **argv) {
    char    buffer;
    while (read(0, &buffer, 1) != 0) {
        if (errno == 0)
            ft_putchar(buffer, 1);
        else {
            ft_putstr(basename(argv[0]), 2);
            ft_putstr(": stdin: ", 2);
            ft_putstr(strerror(errno), 2);
            ft_putchar('\n', 2);
        }
    }
}