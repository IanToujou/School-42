## 💡 EX-01 Explanation

### ✨ Introduction

This exercise is almost the same as the last one, just this time you need to print the alphabet in reverse. You can hard-code it, or soft-code it.

### ✨ Hard-Code

```c
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
  write(1, "zyxwvutsrqponmlkjihgfedcba", 26);
}
```

### ✨ Soft-Code

Like in the previous exercise, we are going to use a `while` loop.

```c
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	letter;

	letter = 'z'; // We start at 'z' this time.
	while (letter >= 'a') // As long as the letter is bigger than 'a', it will continue.
	{
		ft_putchar(letter);
		letter--; // This time, we are going to decrease the number by 1.
	}
}
```

### ✨ Increasing and Decreasing

Increasing a number in C (and many other programming languages) is done by just adding something to it.
```c
int a = 0;
a = a + 5; // We add 5 to a.
```

There is an easier way to write that though.
```c
int a = 0;
a += 5; // Again, we add 5 to a.
a -= 5; // We remove 5 from a.
```

If you only need to add or remove 1 from a variable, you can use the following:
```c
a++; // Add 1 to a.
a--; // Remove 1 from a.
```

This also works with characters of course, because of the ASCII table.
