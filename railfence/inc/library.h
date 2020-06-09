#ifndef RAILFENCE_LIBRARY_H
#define RAILFENCE_LIBRARY_H

/* Includes */
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "stdbool.h"

/* Structures */
typedef struct s_cipher_data
{
    char *string;
    int str_len;
    int key;
    int cycle;
    int rem;
    int *arr;
}             t_cipher_data;

/* Prototypes */
void decode(t_cipher_data *cipherData);
int mx_atoi(char *string);
int mx_strlen(char *string);
void mx_printchar(char chr);
char *create_new_string(unsigned long size);

#endif //RAILFENCE_LIBRARY_H
