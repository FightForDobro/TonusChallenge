#include "library.h"

void print_letter(char letter, int shift)
{

    int base_letter = 97;

    if (is_upper(letter))
        base_letter = 65;

    letter = ((letter - base_letter) + shift) % 26 + base_letter;
    mx_print_char(letter);
}

void decode(char *string, int shift)
{

    while (*string)
    {
        if (is_alpha(*string))
            print_letter(*string, shift);

        else mx_print_char(*string);

        string++;
    }

    mx_print_char('\n');
}
