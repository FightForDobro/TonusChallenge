#include "library.h"

int get_letter_alphabet_index(char letter)
{
    return (letter - 65) % 32;
}


void decode(char *string, char *key)
{
    char cipher_letter;
    char *startPtr = &key[0];

    while (*string)
    {

        if (*key == '\0')
            key = startPtr;

        if (is_alpha(*string))
        {
            cipher_letter = (get_letter_alphabet_index(*string) - get_letter_alphabet_index(*key++) + 26) % 26;

            if (is_upper(*string))
                mx_printchar(cipher_letter + 65);

            else if (is_lower(*string))
                mx_printchar(cipher_letter + 97);

        } else { mx_printchar(*string); }

        string++;
    }

    mx_printchar('\n');
}

