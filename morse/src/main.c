#include "library.h"
#include "stdio.h"

int main(int argc, char **argv)
{

    if (argc != 2)
        raise_error();

    decode(argv[1]);

    return 0;
}
