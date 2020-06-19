#ifndef MORSE_LIBRARY_H
#define MORSE_LIBRARY_H

void hello(void);

/* Includes */
#include <unistd.h>
#include <stdlib.h>

/* Prototypes */
void decode(char *morse_string);
void raise_error();

#endif
