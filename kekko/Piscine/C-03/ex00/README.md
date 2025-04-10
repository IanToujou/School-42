# 💡 EX-00 Explanation

## ✨ Introduction

In this exercise, you need to create a function `ft_strcmp` that takes two strings.
The function will be defined like this:
```c
int ft_strcmp(char *s1, char *s2)
```
The purpose of this function is to compare two strings, and return `0` if there is
no difference, or a number that shows the difference in the ASCII table between the first different
characters.

For example, these two strings are the same:
```
String 1: Hello world
String 2: Hello world
```
The result will be `0`. In the next case, the strings are different:
```
String 1: Hello world
String 2: Hella world
```
The function will stop at the 5th character, which is `o` or `a`. It will then
return the difference between those two. So:
```
o (111 in the ASCII table)
a (97 in the ASCII table)
The difference is o - a, so 111 - 97 = 14
```

## ✨ Creating the Function

To write the function, let's think how we can analyze a string. A string consists
of different characters, so let's first create a loop to loop though all the
characters.
```c
// *s1 in a condition, is the same as writing *s1 != '\0'.
while (*s1) {
    s1++; // Increase the pointer in the first string.
    s2++; // The same for the second string.
}
```
Using `++` on a pointer will move the pointer to the right by one. You want to continue
as long as the first string, s1, is not finished.

The next step is to check if the characters are the same. So if the current value of
s1 and s2 is the same. In the loop it will look like this:
```c
while (*s1 == *s2 && *s1) {
    s1++;
    s2++;
}
```
So, while the current character of s1 and s1 is the same, and if s1 still has characters
left to check.

In the end, we just return the difference between those two.
```c
int ft_strcmp(char *s1, char *s2) {
    while (*s1 == *s2 && *s1) {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}
```
So, in summary, the function will loop through every character until it finds a points where `*s1`
is not equal to `*s2`, and it will return the difference. If the strings are the same, the loop
will stop if s1 has no characters left, and it will still return the difference, which is,
as you may have guessed, `0`, because the last two characters are the same.
