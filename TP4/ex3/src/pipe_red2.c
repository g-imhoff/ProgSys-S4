#include "../header/base.h"
#include "../header/pipe_red2.h"

void raler(const char* msg, int status) {
    if (status < 0) {
        perror(msg);
        exit(status);
    }
}

void raler_null(const char* msg, void* x) {
    if (x == NULL) {
        perror(msg);
        exit(-1);
    }
}

void pipe_red2(const char* username) {
    pid_t child_ps = fork();

    int tube[2];
    int creating_pipe = pipe(tube);
    raler("Erreur lors de la création du pipe", creating_pipe);

    if (child_ps == 0) {

    }

    pid_t child_grep = fork();

    if (child_grep == 0) {

    }

    pid_t child_wc = fork();

    if (child_wc == 0) {

    }
}