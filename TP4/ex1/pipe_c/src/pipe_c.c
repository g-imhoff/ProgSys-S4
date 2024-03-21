#include "../header/base.h"
#include "../header/pipe_c.h"

void raler(const char* msg, int status) {
    if (status < 0) {
        perror(msg);
        exit(status);
    }
}

void ecriture_pipe(void) {
    int tube[2];
    int creating_pipe = pipe(tube);
    raler("Erreur creation du pipe", creating_pipe);

    int close_tube0 = close(tube[0]);
    raler("Erreur lors de la fermeture du tube[0]", close_tube0);

    char buffer[59] =
        "Je suis le fils 1 et je transmets ce message à mon frère";

    int dup_tube1 = dup(tube[1]);
    raler("Erreur de la duplication du tube[1]", dup_tube1);

    ssize_t writing_size = write(1, &buffer, sizeof(buffer));
    raler("Erreur lors de l'ecriture", (int)writing_size);

    int close_tube1 = close(tube[1]);
    raler("Erreur lors de la fermeture du tube[1]", close_tube1);
}

void lecture_pipe(void) {
    int tube[2];
    int creating_pipe = pipe(tube);
    raler("Erreur lors de la création du pipe", creating_pipe);

    int close_tube1 = close(tube[1]);
    raler("Erreur lors de la fermeture du tube[1]", close_tube1);

    ssize_t reading_size;
    char buffer;
    while ((reading_size = read(tube[0], &buffer, 1)) == 1) {
        raler("Erreur de lecture", reading_size);
        printf("%c", buffer);
    }

    printf("\n");
}

int pipe_c(void) {
    pid_t enfant1 = fork();
    raler("Erreur de création d'enfant1", enfant1);

    if (enfant1 == 0) {
        ecriture_pipe();

        pid_t enfant2 = fork();
        raler("Erreur de création d'enfant2", enfant2);

        if (enfant2 == 0) {
            lecture_pipe();
            return 11;
        }

        int wait_enfant2;
        pid_t waiting_enfant2 = waitpid(enfant2, &wait_enfant2, 0);
        raler("Erreur pour attendre la fin de l'enfant2", waiting_enfant2);

        printf("l'enfant 2 ce fini avec %d\n", (int)waiting_enfant2);

        return 12;
    }

    int wait_enfant1;

    pid_t waiting_enfant1 = waitpid(enfant1, &wait_enfant1, 0);
    raler("Erreur pour attendre la fin de l'enfant1", waiting_enfant1);

    printf("l'enfant 2 ce fini avec %d\n", (int)waiting_enfant1);

    return 0;
}