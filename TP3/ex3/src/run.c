#include "../header/base.h"
#include "../header/run.h"

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

int run(const char* cmd, char* const arg[]) {
    pid_t child_pid = fork();
    raler("Erreur lors du fork", child_pid);

    if (child_pid == 0) {
        int return_code = execvp(cmd, arg);
        raler("Erreur lors du execvp", return_code);

        if (return_code < 0) {
            perror("Error: Pas une commande valide");
            return 2;
        }

        return return_code;
    } else {
        int status;
        waitpid(child_pid, &status, 0);

        printf("Mon fils s'est terminé avec le code : %d\n", status);
    }

    return 0;
}