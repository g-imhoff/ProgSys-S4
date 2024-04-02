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
    int tube[2];
    int creating_pipe = pipe(tube);
    raler("Erreur lors de la création du pipe", creating_pipe);   

    pid_t child_ps = fork();
    raler("Erreur lors du fork enfant pour ps", child_ps);

    if (child_ps == 0) {
        int closing_tube0 = close(tube[0]);
        raler("Erreur lors de la fermeture du tube0", closing_tube0);
        int dup_tube1 = dup2(tube[1], STDOUT_FILENO);
        raler("Erreur lors de la duplication du tube1 dans STDOUT_FILENO", dup_tube1);
        int closing_tube1 = close(tube[1]);
        raler("Erreur lors de la fermeture du tube1", closing_tube1);

        int exec_ps = execlp("ps", "ps", "eaux", NULL);
        raler("Erreur lors de l'execution ps", exec_ps);
    } else {
        waitpid(child_ps, NULL, 1);
    }

    pid_t child_grep = fork();
    if (child_grep == 0) {
        int dup_tube1 = dup2(tube[1], STDOUT_FILENO);
        raler("Erreur lors de la duplication du tube1 dans STDOUT_FILENO", dup_tube1);
        int closing_tube1 = close(tube[1]);
        raler("Erreur lors de la fermeture du tube1", closing_tube1);
        int dup_tube0 = dup2(tube[0], STDIN_FILENO);
        raler("Erreur lors de la duplication du tube0 dans le STDIN_FILENO", dup_tube0);
        int closing_tube0 = close(tube[0]);
        raler("Erreur lors de la fermeture du tube0", closing_tube0);

        int exec_grep = execlp("grep", "grep", username, NULL);
        raler("Erreur lors de l'execution du grep", exec_grep);
    } else {
        waitpid(child_grep, NULL, 1);
    }

    pid_t child_wc = fork();
    if (child_wc == 0) {
        int dup_tube1 = dup2(tube[1], STDOUT_FILENO);
        raler("Erreur lors de la duplication du tube1 dans STDOUT_FILENO", dup_tube1);
        int closing_tube1 = close(tube[1]);
        raler("Erreur lors de la fermeture du tube1", closing_tube1);
        int dup_tube0 = dup2(tube[0], STDIN_FILENO);
        raler("Erreur lors de la duplication du tube0 dans le STDIN_FILENO", dup_tube0);
        int closing_tube0 = close(tube[0]);
        raler("Erreur lors de la fermeture du tube0", closing_tube0);
        
        int exec_wc = execlp("wc", "wc", "-l", NULL);
        raler("Erreur lors de l'execution du wc", exec_wc);
    } else {
        waitpid(child_wc, NULL, 1);
    }

    size_t reading_size;
    char buffer;

    int closing_tube1 = close(tube[1]);
    raler("Erreur lors de la fermeture du tube1", closing_tube1);
    int closing_tube0 = close(tube[0]);
    raler("Erreur lors de la fermeture du tube0", closing_tube0);
    
    while((reading_size = read(tube[0], &buffer, 1)) == 1) {
        raler("Reading error", reading_size);
        printf("%c", buffer);
    }

}
