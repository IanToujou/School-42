# 💡 EX-01 Explanation

## ✨ Introduction

In this exercise, you are supposed to print the alphabet. You want to create a function that does this, defined like this:
```c
void	ft_print_alphabet(void) {}
```

It returns `void` (nothing) and takes no arguments. Let's think about how we could create this function. The easiest way is just to hard-code it. Hard-coding means writing something directly inside the code, instead of processing or generating it.

You could do something like this:
```c
#include <unistd.h>

void	ft_print_alphabet(void)
{
  // Remember, 26 here is the amount of characters to print, so the whole alphabet.
  write(1, "abcdefghijklmnopqrstuvwxyz", 26);
}
```

## ✨ Loops
This will work without any problems, but let's not hard-code it. How can we make this work? The answer is, by using a loop.

A loop will repeat as long as a condition is fulfilled, for example:
```c
int x = 0; // Create a number and set it to 0.
while(x < 5) {
  x++; // Increase the number by 1.
}
```

This loop will go on and increase x by 1, until x is NOT smaller than 5 anymore. So, the alphabet has 26 characters, right? So we just need to loop from `a` to `z`.

## ✨ Characters and the ASCII table

Characters can always be represented by a number or by a character. For example:
```c
char a = 'a'; // This character is 'a', but it also has a number, which is 97.
```

You can find these numbers in the ASCII table, either by using [this page](https://www.commfront.com/pages/ascii-chart), or with the command `man ascii`. Using number operations on characters will work for this reason.

In our function, we could write something like this:
```c

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	letter; // Create a character, let's call it letter.

	letter = 'a'; // Set it to 'a', the number would be 97.
	while (letter <= 'z') // Do the loop as long as 'a' (97) is smaller than 'z' (122)
	{
		write(1, &letter, 1); // Write the letter.
		letter++; // Increase the letter by 1.
	}
}
```

And that's it, of course you can still create your `main()` function and test your code!
