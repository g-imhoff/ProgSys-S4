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
    char* file = (char*) malloc(sizeof(char));
    raler_null("Erreur lors du malloc file", (void*) file); 
    char buffer;
    int size_file = 1; 

    int fd = open(filepath, O_RDONLY, 0666);
    raler("Erreur lors de l'ouverture du fichier", fd);

    ssize_t reading_size;

    while((reading_size = read(fd, &buffer, sizeof(char))) == 1) {
        raler("Erreur de lecture", reading_size);
        file[size_file - 1] = buffer;
        size_file++;
        file = realloc(file, (size_t) size_file);
        raler_null("Erreur lors du realloc", file);
    }

    return file;
}


void grep1(const char* username) {
    printf("Hello, %s\n", username);
    pid_t child_pid = fork();
    raler("Erreur lors du fork", child_pid);
    
    if (child_pid == 0) {
        char* toto = reading_toto("./toto.txt");
        write(STDIN_FILENO, toto, strlen(toto));

        execlp("grep", "grep", username, NULL);
    }

    // Attendre la fin du processus enfant
    int status;
    waitpid(child_pid, &status, 0);
}



void script(const char* username) {
    ps1();
    grep1(username);
}