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

    t_cipher_data *cipherData = create_struct(argv);

    decode(cipherData);

    free(cipherData->arr);
    free(cipherData);
    cipherData = NULL;

    return 0;
}

//Do you play checkers? The next cipher is all about a checkerboard. This is a rather old cipher,
//developed back in the sixteenth century. It was also used during the Spanish Civil War to protect
//radio transmissions. Later on, this cipher got incorporated into other, more advanced ones, like
//the VIC cipher and used by Soviet spies.

// To·decrypt·this·cipher,··you·will·need·three·keys.·First·is·a·rearranged·alphabet···
// “csvl.myrpgudxk·iahzojtqenbwf”.·Pay·attention·that·this·alphabet··also·includes·a·
// dot·and·a·space·character,·making·it·a·twenty·eight·letter·alphabet.·Second·and·
// third·keys·are·numbers·three·and·eight.·There·are·not·going·to·be·any··digits·in·
// the·secret·message·and·test·cases,·so·you·don't·have·to·worry·about·that.·Assume·
// digits·are·forbidden·in·plain·text·for·this·cipher.·Binary·for·this·task·must·be·
// called·"checkboard".·And·in·case·of·any·errors·your·program·must·print··"usage:·
// ./checkboard·"text"·"alphabet"·"num1"·"num2""·to·the·standard·error·stream.

