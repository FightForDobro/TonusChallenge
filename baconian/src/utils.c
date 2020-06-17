#include "library.h"

int mx_strlen(const char *string)
{
    int len = 0;

    while (*string++)
        len++;

    return len;

}

void raise_error()
{
    char *error_msg = "./baconian \"str\"\n";
    write(2, error_msg, mx_strlen(error_msg));
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

bool is_alpha(char chr)
{
    return is_upper(chr) || is_lower(chr);
}

void mx_printchar(char chr)
{
    write(1, &chr, 1);
}

int power(int base, int a)
{
    if (a != 0)
        return (base * power(base, a - 1));
    else
        return 1;
}


char *create_string(size_t size)
{
    size++;
    char *string = malloc(size);

    for (size_t i = 0; i <= size ; i++)
        string[i] = '\0';

    return string;
}
