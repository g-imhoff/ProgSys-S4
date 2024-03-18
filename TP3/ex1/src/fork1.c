#include "../header/base.h"

int fork1(void) {
    pid_t child_pid = fork();
    pid_t actual_pid = getpid();

    if (child_pid == 0) {
        pid_t parent_pid = getppid();

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