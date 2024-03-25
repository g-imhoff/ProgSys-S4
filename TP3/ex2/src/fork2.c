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

void fork2(int n) {
    pid_t* tab_pid = (pid_t*)malloc(n * sizeof(pid_t));
    raler_null("Erreur du malloc pour le tableau de pid", tab_pid);

    for (int i = 0; i < n; i++) {
        tab_pid[i] = fork();
        raler("Erreur lors des différent fork", tab_pid[i]);

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
