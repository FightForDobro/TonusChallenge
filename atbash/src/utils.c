#include "library.h"

int mx_strlen(char *string)
{
    int len = 0;

    while (*string++)
        len++;

    return len;
}

void raise_error()
{
    write(2, "usage: ./atbash \"str\"\n", 22);
    exit(0);
}

bool is_upper(char chr)
{
    return chr >= 65 && chr <= 95;
}

bool is_lower(char chr)
{
    return chr >= 97 && chr <= 122;
}

char *create_string(int size)
{
    char *string = malloc(sizeof(char) * size);

    for (int i = 0; i <= size ; i++)
        string[i] = '\0';

    return string;
}

bool is_alpha(char chr)
{
    return is_upper(chr) || is_lower(chr);
}
