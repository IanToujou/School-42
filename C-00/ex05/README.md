## 💡 EX-05 Explanation

### ✨ Introduction

This exercise is a bit more complex. We need to create a function that displays every number, starting from `012` until `789`, where every number is only shown once.

---
### ✨ Create Helper Functions

First of all, we are going to create helper functions. We only need `ft_putchar()` to write.

```c
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```

---
### ✨ Logic

Let's think about this in a logical way. We start at `012`, every number can only be displayed once, and we end at `789`. So, we can try to increase every digit and loop through the three digits.
```
0 -> 7 // The first digit starts at 0, and ends at 7.
1 -> 8 // The same with 1, just until 8.
2 -> 9 // Same.
```

---
### ✨ Write your Code

We have 3 digits, so let's start by creating 3 character variables.
```c
char c1;
char c2;
char c3;
```

You may have guessed, we need loops for this exercise. Since there are three digits, we are going to create three while loops, inside of each other.
```c
void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0'; // c1 is the first digit, so we set it to '0'. It will stop at 7.
	while (c1 <= '7')
	{
		c2 = c1 + 1; // c2 is always +1 compared to the first digit. For example 123, or 789. It will stop at 8.
		while (c2 <= '8')
		{
			c3 = c2 + 1; // c3 is always +1 compared to the second digit. It will stop at 9.
			while (c3 <= '9')
			{
				// Print the numbers
				c3++;
			}
			c2++;
		}
		c1++;
	}
}
```

Hint: `x <= 10` means smaller or equal to 10, and `x < 10` means smaller than 10.

So, finally, we need to print the numbers. The numbers are all separated by `,` and `Space`. So we need to print them inbetween every number. Except for the last one. You don't want a `, ` after the last number.

```c
ft_putchar(c1);
ft_putchar(c2);
ft_putchar(c3);
// This means if c1 is not equal 7, or c2 is not equal 8, or c3 is not equal 9.
// It will print the numbers until c1 is 7, c2 is 8 and c3 is 9, which is the last number.
if (c1 != '7' || c2 != '8' || c3 != '9')
{
  ft_putchar(',');
  ft_putchar(' ');
}
```

However, if we introduce that in our function, the code will be too long. Norminette only wants 25 lines at max per function. We need to create another one to print the digits.
```c
void	ft_out(char c1, char c2, char c3)
{
	ft_putchar(c1);
	ft_putchar(c2);
	ft_putchar(c3);
	if (c1 != '7' || c2 != '8' || c3 != '9')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}
```

And call it with:
```c
ft_out(c1, c2, c3);
```

So, finally, we have our code:
```c
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_out(char c1, char c2, char c3)
{
	ft_putchar(c1);
	ft_putchar(c2);
	ft_putchar(c3);
	if (c1 != '7' || c2 != '8' || c3 != '9')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0';
	while (c1 <= '7')
	{
		c2 = c1 + 1;
		while (c2 <= '8')
		{
			c3 = c2 + 1;
			while (c3 <= '9')
			{
				ft_out(c1, c2, c3);
				c3++;
			}
			c2++;
		}
		c1++;
	}
}
```
