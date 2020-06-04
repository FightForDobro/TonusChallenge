#include "library.h"

int mx_strlen(char *str)
{
    int len = 0;

    while (*str++)
        len++;

    return len;
}

char *create_string(int size)
{
    char *string = malloc(++size);

    for (int i = 0; i <= size; i++)
        string[i] = '\0';

    return string;
}

void print_chr(char chr)
{
    write(1, &chr, 1);
}

void raise_error()
{
    write(2, "usage: ./polybius \"str\"\n", 26);
    exit(0);
}
