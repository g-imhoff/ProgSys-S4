#include "../header/base.h"
#include "../header/fork3.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fork3(argv[1]);

    return EXIT_SUCCESS;
}
