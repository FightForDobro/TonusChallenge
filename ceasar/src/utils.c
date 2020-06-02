#include "library.h"

void mx_print_char(char chr)
{
    write(1, &chr, 1);
}

void raise_error()
{
    write(2, "usage: ./caesar \"str\"\n", 22);
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
//        string--;
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
