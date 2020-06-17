#include "library.h"

t_cipher_data *create_struct(char **argv)
{
    t_cipher_data *cipherData = malloc(sizeof(t_cipher_data));

    cipherData->string = argv[1];
    cipherData->str_len = mx_strlen(cipherData->string);
    cipherData->key = mx_atoi(argv[2]);
    cipherData->cycle = (cipherData->key * 2) - 2;
    cipherData->rem = cipherData->str_len % cipherData->cycle;
    cipherData->arr = malloc(cipherData->key * sizeof(int));

    return cipherData;
}

int main(int argc, char **argv)
{
    //TODO Add number check
    if(argc != 3)
        raise_error();

    t_cipher_data *cipherData = create_struct(argv);

    decode(cipherData);

    free(cipherData->arr);
    free(cipherData);
    cipherData = NULL;

    return 0;
}
