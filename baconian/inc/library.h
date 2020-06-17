#ifndef VIGENERE_LIBRARY_H
#define VIGENERE_LIBRARY_H

/* Includes */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

/* Prototypes */
void decode(char *string);
void mx_printchar(char chr);
void raise_error();
char *create_string(size_t size);
int mx_strlen(const char *string);
int power(int base, int a);
bool is_upper(char chr);
bool is_lower(char chr);
bool is_alpha(char chr);

#endif // VIGENERE_LIBRARY_H
