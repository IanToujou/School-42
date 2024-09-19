#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int    fd;
    char  *next_line;
    int  count;

    count = 0;
    fd = open("example.txt", O_RDONLY);
    while (1) {
        next_line = get_next_line(fd);
        if (next_line == NULL)
            break ;
        count++;
        printf("[%d]:%s\n", count, next_line);
        free(next_line);
        next_line = NULL;
    }
    close(fd);
    return (0);
}