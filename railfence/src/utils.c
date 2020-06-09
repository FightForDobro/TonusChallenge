#include "library.h"


void mx_printchar(char chr)
{
    write(1, &chr, 1);
}

int mx_strlen(char *string)
{
    int len = 0;

    while (*string++)
        len++;

    return len;
}

char *create_new_string(unsigned long size)
{
    char *string = malloc(sizeof(char) * size);

    for (int i = 0; i <= size ; i++)
        string[i] = '\0';

    return string;
}

bool is_whitespace(char chr)
{
    return (chr >= 8 && chr <= 13) || chr == 32;
}

int mx_atoi(char *string)
{
    int sign = 1, base = 0;

    /* Discards all leading whitespaces */
    while (is_whitespace(*string)) string++;

    /* Handle sign */
    if (*string == '-' || *string == '+')
    {
        sign = 1 - 2 * (*string++ == '-');
    //string--;
    }
    // checking for valid input
    while (*string >= '0' && *string++ <= '9') {
        string--;
        // handling overflow test case
        if (base > 2147483647 / 10
            || (base == 2147483647 / 10
                && *string++ - '0' > 7))
        {
            if (sign == 1)
                return 2147483647;
            else
                return -2147483648;
        }
        base = 10 * base + (*string++ - '0');
    }
    return base * sign;
}
