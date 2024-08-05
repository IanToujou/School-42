## 💡 EX-01 Explanation

In this exercise, you need to create a function `ft_strncmp` that takes two strings and an integer.
The function will be defined like this:
```c
int ft_strncmp(char *s1, char *s2, unsigned int n)
```
The purpose of this function is to compare two strings, but only at most n bytes. and return `0` if there is
no difference, or a number that shows the difference in the ASCII table between the first different
characters. It works like ex00, but it will only compare until n.

For example, if `n = 4`, these two strings are the same:
```
String 1: Hello world
String 2: Hella world
It will only check "Hell"
```
The result will be `0`. In the next case, with `n = 4`, the strings are different:
```
String 1: Hello world
String 2: Hallo world
```
Like in the last exercise, it will return the difference.

You also do the same loop as in ex00.
```c
// *s1 in a condition, is the same as writing *s1 != '\0'.
while (*s1 == *s2 && *s1) {
    s1++;
    s2++;
}
```
Only this time, you need to create an index, so a number that will be `0` at first, increasing with every iteration (every loop).
In addition, you need to check whether this index, let's call it `i`, is smaller than `n - 1`, because n is the maximum amount of
characters to check. Since `i` starts at `0`, it's number is smaller by 1 compared to n.
```c
unsigned int i; // Unsigned means without sign, so always positive in this case.

i = 0;
while (*s1 == *s2 && *s1 && (i < n - 1)) {
    s1++;
    s2++;
    i++; // Increase the index.
}
```
In the end, we just return the difference between those two, like in ex00.
```c
int ft_strncmp(char *s1, char *s2, unsigned int n) {
    unsigned int i;

    i = 0;
    while (*s1 == *s2 && *s1 && (i < n - 1)) {
        s1++;
        s2++;
        i++;
    }
    return (*s1 - *s2);
}
```
You also need to check whether `n = 0`, in that case you should always return `0`.
```c
int ft_strncmp(char *s1, char *s2, unsigned int n) {
    unsigned int i;

    i = 0;
    if(n == 0) {
        return (0);
    }
    while (*s1 == *s2 && *s1 && (i < n - 1)) {
        s1++;
        s2++;
        i++;
    }
    return (*s1 - *s2);
}
```
And that's it, it will loop through every character until a difference is found, or if the n-th character is found.
