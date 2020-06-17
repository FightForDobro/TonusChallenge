#include "library.h"

int main(int argc, char **argv)
{
      //TODO Check Number
//    if (mx_atoi(argv[2])) raise_error();

    if (argc != 3) raise_error();

    decode(argv[1], mx_atoi(argv[2]));
}
