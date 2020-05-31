#include "library.h"

void add_letter(char *string, char letter, int letter_id)
{
    int base_letter = 97;

    if (is_upper(letter))
        base_letter = 65;

    string[mx_strlen(string)] = LETTERS_COUNT - letter_id + base_letter;
}

void decode(char *string) {

    char letters[LETTERS_COUNT] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                                   'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                                   'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    char *result_string = create_string(mx_strlen(string));

    while (*string)
    {

        for (int i = 0; i <= LETTERS_COUNT && *string; i++)
        {

            if (i >= LETTERS_COUNT)
                raise_error();

            if (!is_alpha(*string))
            {
                result_string[mx_strlen(result_string)] = *string;
                string++;
            }

            if (letters[i] == *string || letters[i] - 32 == *string)
            {
                add_letter(result_string, *string, i + 1);
                string++;
                break;
            }
        }
    }

    write(1, result_string, mx_strlen(result_string));
    write(1, "\n", 1);
}
