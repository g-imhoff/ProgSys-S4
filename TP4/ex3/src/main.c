#include "../header/base.h"
#include "../header/pipe_red2.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        char* user = getenv("USER");
        pipe_red2(user);
    } else {
        pipe_red2(argv[1]);
    }

    return EXIT_SUCCESS;
}
