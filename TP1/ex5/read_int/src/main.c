#include "base.h"
#include "read_int.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Ce programme nécessite 2 arguments mais a reçu : %d\n", argc);
        exit(EXIT_FAILURE);
    }

    int pos = atoi(argv[2]);

    read_int(argv[1], pos);

    return EXIT_SUCCESS;
}