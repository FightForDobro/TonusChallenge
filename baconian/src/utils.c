#include "library.h"

int mx_strlen(const char *string)
{
    int len = 0;

    while (*string++)
        len++;

    return len;

}

bool is_upper(char chr)
{
    return chr >= 65 && chr <= 95;
}

bool is_lower(char chr)
{
    return chr >= 97 && chr <= 122;
}

bool is_alpha(char chr)
{
    return is_upper(chr) || is_lower(chr);
}

void mx_printchar(char chr)
{
    write(1, &chr, 1);
}

int power(int base, int a)
{
    if (a != 0)
        return (base * power(base, a - 1));
    else
        return 1;
}


char *create_string(size_t size)
{
    size++;
    char *string = malloc(size);

    for (size_t i = 0; i <= size ; i++)
        string[i] = '\0';

    return string;
}


/*
    WELCOME TO ANCIENT GREECE. THE NEXT CIPHER WAS MADE BY AN ANCIENT GREEK HISTORIAN
    AND SCHOLAR POLYBIUS.TO DECRYPT THE SECRET MESSAGE, YOUR SQUARE WILL HAVE THE DIMENSIONS
    SIX BY SIX. AFTER YOU HAVE ADDED ALL THE LETTERS, ADD THE DIGITS FROM ZERO TO NINE. THAT
    SHOULD MAKE A PERFECT SQUARE FOR YOU. ON THE SIDES, USE THE LETTERS A, B, C, D, E, AND
    F.BINARY FOR THIS TASK MUST BE CALLED POLYBIUS.
*/


