#ifndef VIGENERE_LIBRARY_H
#define VIGENERE_LIBRARY_H

/* Includes */
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

/* Prototypes */
void decode(char *string, char *key);
void mx_printchar(char chr);
bool is_upper(char chr);
bool is_lower(char chr);
bool is_alpha(char chr);
void raise_error();

#endif // VIGENERE_LIBRARY_H
