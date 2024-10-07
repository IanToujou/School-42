# 💡 EX-01 Explanation

## ✨ Introduction

In this exercise, we are going to create a function that will be reused a lot in the following exercises. We need to create a function
that writes a string of characters. We created a function that writes a single character, and it will become useful in this exercise.

## ✨ Helper Function

As already mentioned, we know a function to write a single character. We created it in C-01, EX-00:
```c
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```

So we might as well use it. We are not quite finished yet, as we want to write several characters and not just one.
To achieve this, we are using a loop.

## ✨ Creating a Loop

To write all the characters in the string we need to create a loop, like this:
```c
int	i; // Create an index and initialize it to 0.

i = 0;
while (str[i] != '\0') // While the current character of the string exists.
{
	ft_putchar(str[i]); // Print the character.
	i++; // Increase this index.
}
```

This loop will start at the first character in the string (the first position in the char array) and move to the next character as long as it exists (not equal to the NULL terminator byte `\0`).

So our code is finished, and it will look like this:
```c
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
```

That's it. Pretty easy, no?