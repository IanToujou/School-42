## 💡 EX-00 Explanation

### ✨ Introduction

Welcome to your first C exercise! Maybe you have been coding before, maybe not, but it doesn't really matter. C is a bit different from other programming languages. C is a low-level programming language, which means, it operates directly on the components of your PC, like the RAM. Unlike in other languages, you need to
do everything manually in C, like garbage collection (making sure unused variables don't take up space in the RAM), or many functions that exist by default, you need to create them yourself. In the Piscine, you are going to learn how to create simple (and some not so simple) functions. Of course, they exist in some
libraries, but that's not the point.

Before you start, get some basic knowledge in Git, how to use `norminette` and how to create the 42 header!
I would also recommend you watch some videos on basic C programming, variable types, functions, etc.

---
### ✨ What is a function?

In this exercise, you are supposed to create your first function, called `ft_putchar`. It should just print a character. You may have used `print` functions in other languages, but in the piscine, we will also create them ourselves. Every basic function in C is written as follows:
```c
void function_name(int example) {
  // Do something
}
```
Let's break it down first.
- `void` - This is the so-called return type. Every function can return something, which means, give something back. For example, you may want to create a function that generates a random number. In that case, it would return an `int`, an integer.
- `function_name` - This is the name of the function. Functions in C should be all lowercase and may as well contain `_` underscores. Rememeber to name your functions accordingly so it makes sense.
- `int example` - This is an argument of the function. A function takes in parameters to process. Here it takes in a number, of type `int`, and the text followed after the type is just the variable name.
- Every function has `()` after the name, and their code will be executed inside the `{}`.

Now, we are supposed to create a function, `void ft_putchar(char c)`, which has a return type of `void`, so nothing, and it takes in a character as parameter, we call it `c`.
```c
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```
It doesn't matter if you write the `{` on the same line as the function name or not, but in School 42, norminette wants us to make a new line for it.

---
### ✨ The write() function

The line inside our function is this one;
```c
write(1, &c, 1);
```

We are not allowed to use other functions than `write` in this and most exercises. `write` is a C function that prints something in the shell. It will NOT create new lines automatically, and you basically just add a character to the output.

Of course, `write` is also a function, and it takes 3 parameters:
- `1` - Just leave this at 1, you can search on the internet why it is always 1, but at this point just remember to put 1.
- `&c` - This is the character to write. `c` is our character variable, but the `&` sign is not important yet. If you really want to know what it does, it means `get the memory address of` a variable. But that's more important later on.
- `1` - The last parameter is also 1, but this number can change. It is the amount of characters that you want to print. See the following code:
```c
write(1, "A", 1); // Writes "A"
write(1, "Hello", 5); // Writes "Hello"
write(1, "Hello", 2); // Writes "He"
```

So, in the end, we have our function:
```c
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```

---
### ✨ What is #include?

The `write()` function will not work like this. You still need to include it in your program. `write()` is a function from the library `unistd.h`. To include a library, simply add the following code to import it:
```c
#include <unistd.h> // Remember the name of the library!
```
A the end, your code will look like this:
```c
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```

---
### ✨ Testing with main()

Maybe you want to test it, right? That's a great idea! To test it, you need to create another function. This function is called `main()`. It is defined like this:
```c
int  main(void) {
  ft_putchar('A'); // Write your code here.
}
```

Don't worry too much about the function now, but this will get executed once you compile (build) your program.

---
### 🚨 Important Information

Please remember to REMOVE or comment out the main function when you submit your program, if they are asking for a function! A main function only needs to be included if they ask for a program!
