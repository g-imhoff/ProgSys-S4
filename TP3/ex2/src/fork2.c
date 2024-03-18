#include "../header/base.h"

void fork2(int n) {
    pid_t* tab_pid = (pid_t*)malloc(n * sizeof(pid_t));

    for (int i = 0; i < n; i++) {
        tab_pid[i] = fork();

        if (tab_pid[i] == 0) {
            sleep(1);
            exit(EXIT_SUCCESS);
        }
    }

    for (int i = 0; i < n; i++) {
        pid_t return_pid = waitpid(tab_pid[i], NULL, 0);
        printf("Le processus %d est terminé et a renvoyer %d\n", tab_pid[i],
               return_pid);
    }
}
