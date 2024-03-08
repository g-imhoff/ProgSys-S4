#include "base.h"
#include "write_int.h"

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Ce programme nécessite 3 arguments mais a reçu : %d\n", argc);
        exit(EXIT_FAILURE);
    }

    int pos = atoi(argv[2]);
    int64_t value = atoi(argv[3]);

    write_int(argv[1], pos, value);

    return EXIT_SUCCESS;
}