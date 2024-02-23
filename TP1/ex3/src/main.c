#include "base.h"
#include "cp_sys.h"
#include "cp_std.h"

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Ce programme nécessite 4 arguments mais a reçu : %d\n", argc);
        exit(EXIT_FAILURE);
    }

    int buffer_size = atoi(argv[3]);
    cp_sys(argv[1], argv[2], buffer_size);

    return EXIT_SUCCESS;
}
