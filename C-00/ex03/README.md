# 💡 EX-03 Explanation

## ✨ Introduction

This exercise is almost the same as the last one, again. This time, we need to print the numbers from 0 to 9.

## ✨ Hard-Code

```c
#include <unistd.h>

void	ft_print_numbers(void)
{
  write(1, "0123456789", 10);
}
```

## ✨ Soft-Code

Like in the previous exercise, we are going to use a `while` loop.

```c
#include <unistd.h>

void	ft_print_numbers(void)
{
	char	num; // We use characters here, not integers. This will make things easier.

	num = '0'; // The ASCII code of '0' is 48.
	while (num <= '9')
	{
		write(1, &num, 1);
		num++;
	}
}
```

That's it. It's as easy as that.

## ✨ Multiple Functions

You can also add your `ft_putchar()` function to your code. It would look like this:
```c
#include <unistd.h>

// Your function needs to be defined before it will be called. C reads from top to bottom!
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	char	num; // We use characters here, not integers. This will make things easier.

	num = '0'; // The ASCII code of '0' is 48.
	while (num <= '9')
	{
		ft_putchar(num);
		num++;
	}
}
```
