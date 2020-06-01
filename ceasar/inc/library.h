#ifndef CEASAR_LIBRARY_H
#define CEASAR_LIBRARY_H

/* Includes */
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

//TODO Delete
#include <stdio.h>

/* Prototypes */
void decode(char *string, int shift);
void mx_print_char(char chr);
bool is_alpha(char chr);
bool is_upper(char chr);

#endif //CEASAR_LIBRARY_H
