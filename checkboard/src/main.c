#include "library.h"

t_checkBoard *createCheckBoard(char *string, char *alphabet, char *key1, char *key2)
{

    if (mx_strlen(alphabet) != 28) raise_error();

    t_checkBoard *CheckBoard = malloc(sizeof(t_checkBoard));
    CheckBoard->string = string;
    CheckBoard->str_len = mx_strlen(string);
    CheckBoard->alphabet = alphabet;
    CheckBoard->key1 = mx_atoi(key1);
    CheckBoard->key2 = mx_atoi(key2);

    if (CheckBoard->key1 / 10 > 0 || CheckBoard->key2 / 10 > 0)  raise_error();

    /* Fill checkBoard */
    for (int j = 0; j < 3 ; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            CheckBoard->checkBoard[j][i] = '*';
        }
    }

    /* Generate checkBoard */
    for (int i = 0, j = 0; i < 10; i++)
    {
        if (i == mx_atoi(key1) ||  i == mx_atoi(key2))
        {
            continue;
        }
        CheckBoard->checkBoard[0][i] = alphabet[j];
        j++;
    }

    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            CheckBoard->checkBoard[i][j] = alphabet[(10 * i + j) - 2];
        }
    }

    return CheckBoard;

}


int main(int argc, char **argv)
{

    if (argc != 5)
        raise_error();

    t_checkBoard *CheckBoard = createCheckBoard(argv[1], argv[2], argv[3], argv[4]);

    decode(CheckBoard);

    free(CheckBoard);
    return 0;
}
