#include "../header/base.h"

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

int fork1(void) {
    pid_t child_pid = fork();
    raler("Erreur lors du fork", child_pid);
    pid_t actual_pid = getpid();
    raler("Erreur lors du getpid", actual_pid);

    if (child_pid == 0) {
        pid_t parent_pid = getppid();
        raler("Erreur lors de l'obtention du pid parent", parent_pid);

        printf("i'm the child\n");
        printf("Actual process pid: %d\nParent process pid %d\n", actual_pid,
               parent_pid);

        int last_digit = actual_pid % 10;
        return last_digit;
    } else {
        pid_t ending_child_pid = waitpid(child_pid, NULL, 0);

        printf("i'm the parent\n");
        printf("Actual process pid %d\nChild process pid %d\n", actual_pid,
               child_pid);

        return ending_child_pid;
    }
}