#include "../header/base.h"
#include "../header/run.h"

int main(int argc, char* argv[]) {
    const char* cmd = argv[1];
    char* arg[argc-1];

    for (int i = 2; i < argc; i++) {
        arg[i - 2] = argv[i];
    }

    arg[argc - 2] = NULL;

    run(cmd, arg);

    return EXIT_SUCCESS;
}