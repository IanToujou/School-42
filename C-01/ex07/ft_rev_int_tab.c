/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_rev_int_tab.c >                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 07:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/07/11 07:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
    if (nb < 0)
    {
        ft_putchar('-');
        ft_putnbr(-nb);
    }
    else if (nb > 9)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
    else
    {
        ft_putchar(nb + '0');
    }
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	arr[size];
	
	while(index < size)
	{
		arr[0] = *tab;
        ft_putnbr(1);
		tab++;
		index++;
	}
}

int main() {
	int numbers[] = {0,1};
	int *tab = &numbers[0];
	int size = 2;
	ft_rev_int_tab(tab, size);
}
