#ifndef ATBASH_LIBRARY_H
#define ATBASH_LIBRARY_H


/* Includes */
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

// TODO Delete
#include <stdio.h>

/* Defines */

#define LETTERS_COUNT   26

/* Prototypes */
void decode(char *string);
int mx_strlen(char *string);
void raise_error();
char *create_string(int size);
bool is_upper(char chr);
bool is_lower(char chr);
bool is_alpha(char chr);


#endif
