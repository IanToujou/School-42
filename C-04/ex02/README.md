# 💡 EX-02 Explanation

## ✨ Introduction

In this exercise, we are going to create one of the most important functions. We need to create a function,
that writes an integer. Normally when we use `write()`, we can only put chars in the function. So we need
to create our own to write numbers.

There is `printf()` of course from the `<stdio.h>` library, but we are not allowed to use it.

## ✨ Helper Function

Let's start by creating our helper function. We are allowed to use `write()`, and of course our own
functions. In C-01, EX-00 we created the following function:
```c
void ft_putchar(char c) {
    write(1, &c, 1);
}
```

So we might as well use it. However, we cannot simply put a number in the `char c` parameter, because it
will automatically translate it according to the ASCII table.

Doing something like this, will not display anything:
```c
ft_putchar(3);
// Will not display anything. 3 in the ASCII table is not a printable character.
```

## ✨ Converting a Digit to Character

If you look at the ASCII table, you will see that the number `0` has a value of `48`. So the literal (char)
you want to display is `0`, but the id is `48`. You could do something like this, and it will display `0`:
```c
ft_putchar(48);
// Output is 0.
```

## ✨ Converting multiple Digits to Characters

The method above only works with a single digit. If you want to display multiple digits, you need multiple
`write()` functions. We also need to consider different cases. We are handling an integer here, so there are 3 cases we need to consider:
- `Single Digit`
- `Multiple Digits`
- `Negative Numbers`

Let's start with a single digit in our function. Our function will be created as follows:
```c
void ft_putnbr(int nb) {}
```

You remember that the number '0' has an ASCII code of `48`. So, the next number, which is `1`, will have the ASCII code of `49`.
```
'0' is 48.
'1' is 49.
'2' is 50, etc...
```

So we could just simply add '48', right? Just like this:
```c
void ft_putnbr(int nb) {
    ft_putchar(nb + 48);
    ft_putchar(nb + '0'); // Both work and do the same thing.
}
```

However, this will only work for a single digit, we still need to make the additonal checks.

To check whether a number is negative, we can just use an if statement in our function.
```c
void	ft_putnbr(int nb) {
	if (nb < 0) {
		ft_putchar('-'); // Will print a minus sign.
		ft_putnbr(-nb); // Call this function again, but this time with the positive number. Minus a minus number is positive.
	}
	else
	{
		ft_putchar(nb + 48); // Print a single digit.
	}
}
```

What we just did is called a recursive function. We are calling the function inside our function, and yes that works and it will be very useful later on. There are also other ways to do this,
like multiplying the number by -1 and continuing, but I find this a bit more readable.
```c
ft_putnbr(6); // Result will be 6.
ft_putnbr(-5): // Result will be -5.
```

Now we need to start with the next part. We need to print multiple digits, how do we do that? For our reasoning, let's use an example value of 42. It's always a good idea to think about
example cases to understand the logic better. How do we split 42 into different digits? With division!
```
42 / 10 = 4 (We ignore the rest because we are working with integers, full numbers).
```

And to get the rest, we use the modulo `%` operator. Module will divide by the second number and return the rest.
```
42 % 10 = 2 (42 divided by 10 is 4, rest 2)
```

We need to repeat this exact procedure for every single digit, except the last one. So let's introduce another if statement, when the number is bigger or equals to `10`.
```c
void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10); // Take the first digit(s), we seperate the last digit.
		ft_putnbr(nb % 10); // Process the last digit.
	}
	else
	{
		ft_putchar(nb + '0');
	}
}
```

We are going to seperate the digits 1 by 1, always dropping the last digit, until there is only one single digit left. If we create a graph, it would look like this:

![Graph](https://github.com/user-attachments/assets/033b29ee-94a1-4afe-9575-4df287eaf3a7)

## ✨ Minimum Integer

If we try to submit this, moulinette will say it's wrong, but why? Well, integers have a minimum and maximum value, and if we try to do these calculations with the minimum integer, we
need to check it manually. I don't fully understand why only on the negative bound, but you can open an issue and tell me if you know!
```c
// -2147483648 is the minimum integer.
if (nb == -2147483648) {
    ft_putnbr(nb / 10);
    ft_putchar('8'); // Print '8' because it is the last character.
}
```
> You can find this number by calculating 2 ^ 31 (2 to the power of 31). Or just by brute-forcing it.

So our code is finished, and it will look like this:
```c
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
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
		ft_putchar(nb + '0');
}
```
