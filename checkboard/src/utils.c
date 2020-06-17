#include "library.h"

void print_char(char chr)
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

bool is_digit(char chr)
{
    return chr >= 48 && chr <= 57;
}

void raise_error()
{
    char *error_msg = "./checkboard \"text\" \"alphabet\" \"num1\" \"num2\"\n";
    write(2, error_msg, mx_strlen(error_msg));
    exit(0);
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
