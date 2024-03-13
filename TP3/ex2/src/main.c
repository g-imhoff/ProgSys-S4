#include "../header/base.h"
#include "../header/fork2.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    fork2(n);

    return EXIT_SUCCESS;
}
