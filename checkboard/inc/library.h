#ifndef CHECKBOARD_LIBRARY_H
#define CHECKBOARD_LIBRARY_H

/* Includes */
#include "stdlib.h"
#include "unistd.h"
#include "stdbool.h"

/* Structures */
typedef struct s_checkBoard
{

    char *string;
    int str_len;

    char *alphabet;
    int key1;
    int key2;

    char checkBoard[3][10];

}             t_checkBoard;

/* Prototypes */
int mx_atoi(char *string);
void decode(t_checkBoard *checkBoard);
int mx_strlen(char *string);
void print_char(char chr);
bool is_digit(char chr);
void raise_error();

#endif //CHECKBOARD_LIBRARY_H
