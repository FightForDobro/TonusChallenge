#include "library.h"

t_checkBoard *createCheckBoard(char *string, char *alphabet, char *key1, char *key2)
{
    t_checkBoard CheckBoard = {.string = string, .alphabet = alphabet, .key1 = mx_atoi(key1), .key2 = mx_atoi(key2)};

    char checkBoard[3][9];

    /* Generate checkBoard */
    for (int i = 0; i < 9; i++)
    {
        if (i == checkBoard)
            checkBoard[0][i] == alphabet[i];
    }

};


int main(int argc, char **argv)
{



    return 0;
}
