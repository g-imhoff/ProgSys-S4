#include "../header/base.h"
#include "../header/pipe_a.h"

int main() {
    pid_t pid_fork = fork();

    if (pid_fork != 0) {
        ecriture_pipe();
    } else {
        lecture_pipe();
    }

    return EXIT_SUCCESS;
}
