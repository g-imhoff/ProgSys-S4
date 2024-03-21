#include "base.h"
#include "cp_sys.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("This program needs 2 arguments but as : %d", argc);
        exit(EXIT_FAILURE);
    }

    cp_sys(argv[1], argv[2]);

    return EXIT_SUCCESS;
}