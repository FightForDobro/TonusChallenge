#ifndef CHECKBOARD_LIBRARY_H
#define CHECKBOARD_LIBRARY_H

/* Includes */
#include "stdlib.h"
#include "stdbool.h"

/* Structures */
typedef struct s_checkBoard
{

    char *string;
    char *alphabet;
    int key1;
    int key2;

    char **checkBoard;

}             t_checkBoard;

/* Prototypes */
int mx_atoi(char *string);

#endif //CHECKBOARD_LIBRARY_H
