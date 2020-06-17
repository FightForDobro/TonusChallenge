#include "library.h"

void decode(t_checkBoard *checkBoard)
{

    for (int i = 0; i <= checkBoard->str_len; i++)
    {

        if (!is_digit(checkBoard->string[i]))
            print_char(checkBoard->string[i]);

        else if (checkBoard->string[i] - 48 == checkBoard->key1)
            print_char(checkBoard->checkBoard[1][checkBoard->string[++i] - 48]);

        else if (checkBoard->string[i] - 48 == checkBoard->key2)
            print_char(checkBoard->checkBoard[2][checkBoard->string[++i] - 48]);

        else
            print_char(checkBoard->checkBoard[0][checkBoard->string[i] - 48]);
    }
    print_char('\n');
}
