#include "../header/base.h"
#include "../header/script.h"

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

void ps1(void) {
    int tube[2];
    raler("Erreur lors de la création du pipe", pipe(tube));

    pid_t child_pid = fork();
    raler("Erreur lors du fork", child_pid);

    if (child_pid == 0) {
        int closing_tube0 = close(tube[0]);
        raler("Erreur lors de la fermeture du tube en lecture", closing_tube0);

        int duplication_tube1 = dup2(tube[1], STDOUT_FILENO);
        raler("Erreur lors de la duplication du tube1", duplication_tube1);
        int closing_tube1 = close(tube[1]);
        raler("Erreur lors de la fermeture du tube1", closing_tube1);

        execlp("ps", "ps", "eaux", NULL);
    } else {
        int closing_tube1 = close(tube[1]);
        raler("Erreur lors de la fermeture du tube en ecriture", closing_tube1);

        int fd_toto = open("./toto.txt", O_WRONLY | O_CREAT, 0666);
        raler("Erreur lors de l'ouverture de toto", fd_toto);

        char buffer;
        ssize_t reading_size, writing_size;
        while ((reading_size = read(tube[0], &buffer, sizeof(char))) == 1) {
            raler("Erreur lors de la lecture du tube[0]", reading_size);
            writing_size = write(fd_toto, &buffer, sizeof(char));
            raler("Erreur lors de l'écriture dans toto", writing_size);
        }
    }
}

char* reading_toto(const char* filepath) {
    char* file = (char*)malloc(sizeof(char));
    raler_null("Erreur lors du malloc file", (void*)file);
    char buffer;
    int size_file = 1;

    int fd = open(filepath, O_RDONLY, 0666);
    raler("Erreur lors de l'ouverture du fichier", fd);

    ssize_t reading_size;

    while ((reading_size = read(fd, &buffer, sizeof(char))) == 1) {
        raler("Erreur de lecture", reading_size);
        file[size_file - 1] = buffer;
        size_file++;
        file = realloc(file, (size_t)size_file);
        raler_null("Erreur lors du realloc", file);
    }

    return file;
}

void grep1(const char* username) {
    int tube[2];
    int creating_pipe = pipe(tube);
    raler("Erreur lors de la creation du pipe", creating_pipe);
    
    pid_t child_pid = fork();
    raler("Erreur lors du fork", (int)child_pid);

    if (child_pid == 0) {
        int closing_tube1 = close(tube[1]);
        raler("Erreur lors de la fermeture du tube1 enfant", closing_tube1);

        int duplication_tube0 = dup2(tube[0], STDIN_FILENO);
        raler("Erreur lors de la duplication du tube0  enfant",
              duplication_tube0);
        int closing_tube0 = close(tube[0]);
        raler("Erreur lors de la fermeture du tube0 enfant", closing_tube0);

        int null_fd = open("/dev/null", O_WRONLY);
        dup2(null_fd, STDOUT_FILENO);

        execlp("grep", "grep", username, NULL);
    } else {
        int closing_tube0 = close(tube[0]);
        raler("Erreur lors de la fermeture du tube0 parent", closing_tube0);

        int duplication_tube1 = dup2(tube[1], STDOUT_FILENO);
        raler("Erreur lors de la duplication du tube1  parent", duplication_tube1);

        char* toto = reading_toto("./toto.txt");
        write(tube[1], toto, strlen(toto));

        int closing_tube1 = close(tube[1]);
        raler("Erreur lors de la fermeture du tube1 parent", closing_tube1);

        int status;
        waitpid(child_pid, &status, -1); // Attendre que le processus enfant se termine
        if (WEXITSTATUS(status) == 0) {
            printf("%s est connecté", username);
        }
    }
}

void script(const char* username) {
    ps1();
    grep1(username);
}