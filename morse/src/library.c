#include "library.h"
#include "stdio.h"

void raise_error()
{
    write(2, "usage: ./morse \"str\"\n", 22);
    exit(0);
}

char *create_string(int size)
{
    char *string = malloc(size);

    for (int i = 0; i < size; i++)
        string[i] = '\0';

    string[size] = '\0';

    return string;
}

char *mx_strchr(char *string, char pattern, int delete_space)
{
    while (*string != pattern)
    {
        if (*string == '\0')
            return "\0";

        string++;
    }
    if (delete_space)
        while (*string == pattern)
        {
            if (*string == '\0')
                return "\0";
            string++;
        }
    else
        string++;

    return string;
}

int mx_strlen(char *string)
{
    int len = 0;

    while (*string++)
        len++;

    return len;
}

int mx_strcmp(char *x, char *y)
{
    if (mx_strlen(x) != mx_strlen(y)) return 0;

    while (*x)
    {
        if (*x != *y) return 0;
        x++;
        y++;
    }

    return 1;
}

void print_letter(int letter_id, char *decoded_string)
{
    char morse_letters[28] = {
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
            'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
            'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '.', ' ', '\n'};

    decoded_string[mx_strlen(decoded_string)] = morse_letters[letter_id];
}

void find_morse_code_id(char *morse_letter_code, char *decoded_string)
{
    int i;

    char *morse_code[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                            "....", "..", ".---", "-.-", ".-..", "--", "-.",
                            "---", ".--.", ".-.", "...", "-", "..-", "...-",
                            ".--", "-..-", "-.--", "--..", "....."};

    for (i = 0; i <= 26 ; i++)
    {
        if (i >= 26) raise_error();
        if (mx_strcmp(morse_letter_code, morse_code[i]))
        {
            print_letter(i, decoded_string);
            break;
        }
    }
}

char *decode_letter(char *morse_string, char *decoded_string)
{
    char *morse_letter = create_string(10);

    int delete_space = 0;
    char pattern = ' ';

    for (int i = 0; morse_string[i]; i++)
    {
        if (morse_string[i] == '\n' || (morse_string[i] == '\\' && morse_string[i + 1] == 'n'))
        {
            pattern = 'n';

            if (morse_string[i] == '\\' && morse_string[i + 1] == 'n')
                morse_string = mx_strchr(morse_string, '\\', 0);
            else
                pattern = '\n';

            find_morse_code_id(morse_letter, decoded_string);
            print_letter(27, decoded_string);
            free(morse_letter);
            break;
        }

        if (morse_string[i] == ' ')
        {

            if (morse_letter[0] == '\0')
            {
                delete_space = 1;
                print_letter(26, decoded_string);
                free(morse_letter);
                break;
            }

            find_morse_code_id(morse_letter, decoded_string);
            free(morse_letter);
            break;
        }

        if (morse_string[i] != '.' && morse_string[i] != '-' && morse_string[i] != ' ' && morse_string[i] != '\0')
            raise_error();

        morse_letter[i] = morse_string[i];
    }

    if (morse_letter[0] != '\0')
    {
        find_morse_code_id(morse_letter, decoded_string);
        free(morse_letter);
    }

    return mx_strchr(morse_string, pattern, delete_space);
}

void decode(char *morse_string)
{
    char *decoded_string = create_string(mx_strlen(morse_string));

    while (*morse_string)
        morse_string = decode_letter(morse_string, decoded_string);

    write(1, decoded_string, mx_strlen(decoded_string));
    write(1, "\n", 1);
}
