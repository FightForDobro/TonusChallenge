#include "library.h"

void prepare_data(t_cipher_data *cipherData)
{
    /* Find first string len */
    cipherData->arr[0] = cipherData->str_len / cipherData->cycle;

    /* Find middle strings */
    for (int i = 1; i < cipherData->key - 1; i++)
        cipherData->arr[i] = cipherData->arr[0] * 2;

    /* Find last string len */
    cipherData->arr[cipherData->key - 1] = cipherData->str_len / cipherData->cycle;

    /* Process rem */
    int i;

    for (i = 0; cipherData->rem && i != cipherData->key; i++, cipherData->rem--)
         cipherData->arr[i]++;

    for (i = cipherData->key - 2; cipherData->rem ; i--, cipherData->rem--)
        cipherData->arr[i]++;
}

char **make_substrings(t_cipher_data *cipherData)
{
    char **result = malloc(sizeof(char *) * cipherData->key);

    for (int j = 0; j < cipherData->key; j++)
        result[j] = create_new_string(sizeof(char) * cipherData->arr[j] + 1);

    for (int k = 0; k < cipherData->key;)
    {

        int k_len = mx_strlen(result[k]);

        if (k_len >= cipherData->arr[k])
            k++;

        else { result[k][k_len] = *cipherData->string++; }
    }

    return result;
}

void print_data(t_cipher_data *cipherData)
{
    char **substrings = make_substrings(cipherData);

    int row_selector = 0;
    int way = 1;

    /* Collect Garbage */
    char *garbage[cipherData->key];

    for (int j = 0; j < cipherData->key; j++)
        garbage[j] = substrings[j];

    while (cipherData->str_len--)
    {
        if (row_selector == cipherData->key - 1)
            way = -1;
        else if (row_selector == 0)
            way = 1;

        mx_printchar(*substrings[row_selector]);
        substrings[row_selector]++;
        row_selector += way;
    }

    for(int i = 0; i < cipherData->key; i++)
        free(garbage[i]);

    free(substrings);
    substrings = NULL;
}

void decode(t_cipher_data *cipherData)
{

    prepare_data(cipherData);
    print_data(cipherData);
}
