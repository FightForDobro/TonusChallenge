#include "library.h"

int main(int argc, char **argv)
{

    if (argc != 3) raise_error();

    decode(argv[1], mx_atoi(argv[2]));
}
