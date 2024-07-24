#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    const int file = open(argv[1], O_RDONLY | O_CREAT);
    char    *buffer = malloc(100 * sizeof(char));
    read(file, buffer, 100);
    printf("ID: %d\n", file);
    printf("Content: %s\n", buffer);
    close(file);
}
