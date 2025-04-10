# 💡 EX-04 Explanation

## ✨ Introduction

Here, we are going to create a function called `ft_is_negative()` that will, well, check if a number is negative.

## ✨ Create the Function

You still know how to create a function, right? So let's create it:
```c
void	ft_is_negative(int n) {}
```

## ✨ If & Else Statements

According to the subject, we need to print 'P' if the number is positive, and 'N' if the number is negative. We could write it in one line using ternaries, but norminette doesn't allow us to do so. We need to write it using `if` and `else`.

A number is negative if it's below 0, so let's check if a number is below zero. To do that, we use an `if` statement.

```c
if (number < 0) {
  // Do something
}
```

We can also add else at the end of the if statement to create the code that will be executed when the condition is not true.

```c
if (number < 0) {
  // Do something
} else {
  // Do something else
}
```

So let's implement that in our function:

```c
#include <unistd.h> // Don't forget to include this if you use write!

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		write(1, "N", 1);
	}
	else
	{
		write(1, "P", 1);
	}
}
```

## ✨ Making the Code smaller

The code can also be made simpler. If there is only ONE line of code inside the `if` or `else` statement, you can drop the `{}`. Just remember to use the proper indentation (`TAB`)!

```c
#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
            write(1, "N", 1);
	else
            write(1, "P", 1);
}
```

Of course, we can also test this again, or you can also replace `write()` with your own function, like `ft_putchar()`, but you need to create it first.
