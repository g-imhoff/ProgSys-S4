#include "../header/base.h"
#include "../header/pipe_b.h"

void raler(const char* msg, int status) {
    if (status < 0) {
        perror(msg);
        exit(status);
    }
}

void ecriture_pipe(void) {
    int tube[2];
    int creating_pipe = pipe(tube);
    raler("Erreur dans la création du pipe", creating_pipe);

    int close_tube0 = close(tube[0]);
    raler("Erreur pour fermer tube[0]", close_tube0);

    char buffer[56] = "Je suis le fils et je transmets ce message à mon père";

    int duplication = dup(tube[1]);
    raler("Ne peux pas duppliquer le descripteur en ecriture", duplication);

    int writing = write(1, &buffer, sizeof(buffer));
    raler("Erreur d'ecriture", writing);

    int close_tube1 = close(tube[1]);
    raler("Erreur pour fermer tube[1]", close_tube1);
}

void lecture_pipe(void) {
    int tube[2];
    int creating_pipe = pipe(tube);
    raler("Erreur dans la création du pipe", creating_pipe);

    int close_tube1 = close(tube[1]);
    raler("Erreur pour fermer tube[1]", close_tube1);

    char buffer;
    ssize_t reading_size;
    while ((reading_size = read(tube[0], &buffer, 1)) == 1) {
        raler("Erreur de lecture", (int)reading_size);
        printf("%c", buffer);
    }

    printf("\n");

    int close_tube0 = close(tube[0]);
    raler("Erreur pour fermer tube[0]", close_tube0);
}

void pipe_b(void) {
    pid_t pid_fork = fork();

    if (pid_fork == 0) {
        ecriture_pipe();
    } else {
        int wait_pid = waitpid(pid_fork, NULL, 0);
        raler("Erreur avec la fonction waitpid", wait_pid);

        lecture_pipe();
    }
}
