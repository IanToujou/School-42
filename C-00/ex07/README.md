# 💡 EX-07 Explanation

## ✨ Introduction

In this exercise, we are going to create one of the most important functions. We need to create a function,
that writes an integer. Normally when we use `write()`, we can only put chars in the function. So we need
to create our own to write numbers.

There is `printf()` of course from the `<stdio.h>` library, but we are not allowed to use it.

## ✨ Helper Function

Let's start by creating our helper function. We are allowed to use `write()`, and of course our own
functions. In EX-00 we created the following function:
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

🚧 Work in progress...