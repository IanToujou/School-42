/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 08:57:18 by ibour             #+#    #+#             */
/*   Updated: 2024/07/20 08:57:20 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putstring(char* str)
{
    while(*str != '\0')
    {
        ft_putchar(*str);
        str++;
    }
}

void	handle_error()
{
    ft_putstring("Error");
    ft_putchar('\n');
}

bool check_input_format_recursive(char *input, int i) {
    if (input[i] != '\0')
    {
        if ((i % 2 == 0 && (input[i] < '1' || input[i] > '4')) ||
            (i % 2 == 1 && input[i] != ' '))
        {
            return 0;
        }
        return check_input_format_recursive(input, i + 1);
    }
    return 1;
}

bool check_input_format(char *input)
{
    return check_input_format_recursive(input, 0);
}