#include "library.h"

int main(int argc, char **argv)
{
    // TODO Add check for argv[2] int ?
    if (argc != 3) raise_error();

    decode(argv[1], mx_atoi(argv[2]));
}
