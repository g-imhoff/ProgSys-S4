#include "../header/base.h"
#include "../header/pipe_red1c.h"

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

void pipe_red1c(void) {
    int tube[2];
    int creating_pipe = pipe(tube);
    raler("Erreur lors de la creation du pipe", creating_pipe);

    pid_t child1_pid = fork();
    raler("Erreur lors du fork", (int)child1_pid);

    if (child1_pid == 0) {
        int closing_tube0 = close(tube[0]);
        raler("Erreur lors de la fermeture du tube0 parent", closing_tube0);

        int duplication_tube1 = dup2(tube[1], STDOUT_FILENO);
        raler("Erreur lors de la duplication du tube1  parent",
              duplication_tube1);
        int closing_tube1 = close(tube[1]);
        raler("Erreur lors de la fermeture du tube1 parent", closing_tube1);

        execlp("ls", "ls", "-l", NULL);
    }

    waitpid(child1_pid, NULL, 1);

    pid_t child2_pid = fork();

    if (child2_pid == 0) {
        int closing_tube1 = close(tube[1]);
        raler("Erreur lors de la fermeture du tube1 enfant", closing_tube1);

        int duplication_tube0 = dup2(tube[0], STDIN_FILENO);
        raler("Erreur lors de la duplication du tube0  enfant",
              duplication_tube0);
        int closing_tube0 = close(tube[0]);
        raler("Erreur lors de la fermeture du tube0 enfant", closing_tube0);

        execlp("wc", "wc", "-l", NULL);
    }

    waitpid(child2_pid, NULL, 1);
}