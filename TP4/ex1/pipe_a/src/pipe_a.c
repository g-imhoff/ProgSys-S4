#include "../header/base.h"
#include "../header/pipe_a.h"

void raler(const char* msg, int status) {
    if (status < 0) {
        perror(msg);
        exit(status);
    }
}

void raler_malloc(void* item) {
    if (item == NULL) {
        perror("malloc a echouer");
        exit(1);
    }
}

void ecriture_pipe(void) {
    int tube[2];
    int creating_pipe = pipe(tube);
    close(tube[0]);
    raler("Ne peux pas créer le pipe", creating_pipe);

    int dup_pipe = dup(tube[1]);
    raler("Ne peux pas duppliquer le descripteur en ecriture", dup_pipe);

    char buffer[56] = "Je suis le père et je transmets ce message à mon fils";

    write(1, &buffer, sizeof(buffer));

    close(tube[1]);
}

void lecture_pipe(void) {
    int tube[2];
    int creating_pipe = pipe(tube);
    close(tube[1]);

    raler("Ne peux pas créer le pipe", creating_pipe);
    char* buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
    raler_malloc((void*)buffer);
    read(tube[0], buffer, sizeof(buffer));

    printf("%s\n", buffer);
}