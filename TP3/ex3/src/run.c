#include "../header/base.h"
#include "../header/run.h"

int run(const char* cmd, char* const arg[]) {
    pid_t child_pid = fork();

    if (child_pid == 0) {
        int return_code = execvp(cmd, arg);

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