#include "base.h"
#include "my_stat.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Ce programme nécessite 2 arguments mais a reçu : %d\n", argc);
        exit(EXIT_FAILURE);
    }

    my_stat(argv[1]); 

    return EXIT_SUCCESS;
}