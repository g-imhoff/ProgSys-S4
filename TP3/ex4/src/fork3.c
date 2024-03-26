#include "../header/base.h"
#include "../header/fork3.h"

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

void fork3(const char* filepath) {
    pid_t pid = fork();
    raler("Erreur lors du fork", pid);

    int file = open(filepath, O_RDONLY);
    raler("Erreur lors de l'ouverture du fichier", file);

    char buffer;

    ssize_t readsize = read(file, &buffer, 1);
    raler("Erreur lors de la lecture du fichier", (int)readsize);

    int nbr_char_lu = (int)readsize;
    while (readsize > 0) {
        ssize_t sortie_standard_write = write(STDOUT_FILENO, &buffer, 1);
        raler("Erreur lors de l'écriture dans la sortie standard",
              (int)sortie_standard_write);
        readsize = read(file, &buffer, 1);
        raler("Erreur lors de la lecture du fichier", (int)readsize);
        nbr_char_lu++;
    }

    // printf("Le nombre de char lu : %d", nbr_char_lu);
}