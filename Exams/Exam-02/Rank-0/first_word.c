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

int main(int argc, char **argv)
{
    ft_putstr(argv[argc-1]);
}