#include "../header/base.h"
#include "../header/script.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    script(argv[1]);

    return EXIT_SUCCESS;
}
