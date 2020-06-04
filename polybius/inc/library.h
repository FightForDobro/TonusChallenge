#ifndef BACONIAN_LIBRARY_H
#define BACONIAN_LIBRARY_H

/* Includes */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

/* Prototypes */
void decode(char *string);
char *create_string(int size);
void print_chr(char chr);
int mx_strlen(char *str);
void raise_error();

#endif // BACONIAN_LIBRARY_H
