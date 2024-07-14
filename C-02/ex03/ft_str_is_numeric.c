/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:02:38 by ibour             #+#    #+#             */
/*   Updated: 2024/07/14 14:02:39 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_numeric(char* str)
{
    char    c;

    c = *str;
    while(c != '\0')
    {
        c = *str;
        if (!(c >= '0' && c <= '9') && c != 0)
        {
            return (0);
        }
        str++;
    }
    return (1);
}

/*int main(int argc, char** argv)
{
    printf("Testing string: %s\n", argv[1]);
    printf("Result: %d\n", ft_str_is_numeric(argv[1]));
}*/