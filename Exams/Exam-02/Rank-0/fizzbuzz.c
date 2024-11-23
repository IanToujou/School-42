#include <io.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    while (*str)
    {
        ft_putchar(*str);
        str++;
    }
}

void ft_putnbr(int nb)
{
    if (nb <= 0)
        ft_putchar('0');
    else
        ft_putnbr(nb / 10);
    ft_putnbr(nb % 10);
}

int main(int argc, char **argv)
{

}