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
