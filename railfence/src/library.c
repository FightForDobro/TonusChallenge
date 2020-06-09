#include "library.h"
//
//void parse_string(char *string)
//{
//
//}
//
//void decode(char *string, int key)
//{
//
////    char *rails[key];
////
////    for (int i = 0; i < key; i++)
////    {
////        string
////    }
//
//    int STR_LEN = 29;
//
//    int array[key];
//
//    for (int i = 0; i < key; i++)
//        array[i] = 0;
//
//    int cycles = key * 2 - 2;
//    int rem = STR_LEN % cycles;
//    int mul;
//    int add = 0;
//
//    for (int j = 0; j < key; j++, rem--)
//    {
//
//        if (j != 0 && j + 1 != key)
//            mul = 2;
//        else
//            mul = 1;
//
//        if (rem)
//            add = 1;
//
//        else if (!rem)
//            add = 0;
//
//
//        array[j] = ( (STR_LEN / cycles ) * mul ) + add;
//    }
//
//    printf("A");
//}
//                                              //25
////1 . . . . . 1 . . . . . 1 . . . . . 1 . . . . . 1 . . . . . .
////. 2 . . . 6 . 2 . . . 6 . 2 . . . 6 . 2 . . . 6 . 2 . . . . .
////. . 3 . 5 . . . 3 . 5 . . . 3 . 5 . . . 3 . 5 . . . 3 . 5 . .
////. . . 4 . . . . . 4 . . . . . 4 . . . . . 4 . . . . . 4 . . .

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

//    for (int i = 0; i < cipherData->key ; i++)
//    {
//        int iter = cipherData->arr[i];
//
//        result[i][iter] = '\0';
//
//        while (iter)
//        {
//            result[i][iter - 1] = cipherData->string[iter - 1];
//            iter--;
//        }
//    }

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

}

void decode(t_cipher_data *cipherData)
{

    prepare_data(cipherData);
    print_data(cipherData);
}
