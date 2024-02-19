#include "base.h"
#include "cp_sys.h"

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("This program needs 3 arguments but as : %d", argc);
        exit(EXIT_FAILURE);
    }

    int buffer_size = atoi(argv[3]);
    printf("%d \n", buffer_size);
    cp_sys(argv[1], argv[2], buffer_size);

    return EXIT_SUCCESS;
}