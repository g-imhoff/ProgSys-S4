#include "base.h"
#include "cp_rev.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Ce programme nécessite 4 arguments mais a reçu : %d\n", argc);
        exit(EXIT_FAILURE);
    }

    cp_rev(argv[1], argv[2]);

    return EXIT_SUCCESS;
}