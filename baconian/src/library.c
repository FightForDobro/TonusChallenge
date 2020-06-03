#include "library.h"

char *format_string(char *string)
{
    //TODO Free that memory
    char *formatted_string = create_string(mx_strlen(string));

    while (*string)

        if (is_alpha(*string))
        {

            if (is_lower(*string))
                formatted_string[mx_strlen(formatted_string)] = 'A';
            else
                formatted_string[mx_strlen(formatted_string)] = 'B';

            string++;

        } else { string++; }

    return formatted_string;
}

int count_binary_code(int binary_of_ba[5])
{
    int result = 0;

    for (int i = 0, j = 4; i < 5; i++, j--)
        if (binary_of_ba[i])
            result += power(2, j);

    return result;
}

void parse_code(char *ba_code)
{
    if (*ba_code)
    {
        int binary_of_ba[5] = {1, 1, 1, 1, 1};

        for (int i = 0; i < 5; i++)
            binary_of_ba[i] -= *ba_code++ & 1;

        int code = count_binary_code(binary_of_ba);

        if (code < 26)
            mx_printchar(code + 65);

        switch (code)
        {
            case 26:
                mx_printchar(' ');
                break;

            case 27:
                mx_printchar('.');
                break;

            case 28:
                mx_printchar(',');
                break;
        }
        return parse_code(ba_code);
    }
}

void decode(char *string)
{
    char *formatted_string = format_string(string);
    parse_code(formatted_string);
}
