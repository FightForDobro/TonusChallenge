#include "library.h"

void parse_code(char *string, char *result)
{
    int code_index = 0;

    if (*string != '\0')
    {
        if (*string >= 9 && *string <= 13 || *string >= 32 && *string <= 47)
        {
            *result = *string++;
            return parse_code(string, ++result);
        }
        else

           for (int i = 0; i < 2 ; ++i, code_index *= 10)
                code_index += *string++ - 64;

            code_index /= 10;

            if (code_index >= 11 && code_index <= 52)
                *result = code_index + 54 - (code_index / 10 - 1) * 4;

            else if (code_index >= 53 && code_index <= 66)
                *result = code_index + 11 - (code_index / 10 - 1) * 4;

            else raise_error();

            return parse_code(string, ++result);
    }
}

void decode(char *string)
{
    char *result = create_string(mx_strlen(string));
    parse_code(string, &result[0]);

    write(1, result, mx_strlen(result));
}
