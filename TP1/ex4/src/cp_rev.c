#include "base.h"
#include "cp_rev.h"

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

void cp_rev(const char* filepath1, const char* filepath2) {
    int file1 = open(filepath1, O_RDONLY);
    raler("Erreur lors de l'ouverture du fichier1", file1);
    int file2 = open(filepath2, O_CREAT | O_WRONLY, 0666);
    raler("Erreur lors de l'ouverture du fichier2", file2);

    off_t file_size = lseek(file1, -1, SEEK_END);
    raler("Erreur lors du positionnement du pointeur à la fin du fichier",
          (int)file_size);

    char* c = (char*)malloc(sizeof(char));
    raler_null("Erreur lors du malloc", (void*)c);

    ssize_t nbr_bytes_read, nbr_bytes_write;
    off_t nbr_bytes_lseek = 1;
    do {
        raler("Erreur lors du positionnement du pointeur",
              (int)nbr_bytes_lseek);
        nbr_bytes_read = read(file1, c, 1);
        raler("Erreur lors de la lecture", (int)nbr_bytes_read);
        nbr_bytes_write = write(file2, c, 1);
        raler("Erreur lors de l'écriture", (int)nbr_bytes_write);
    } while ((nbr_bytes_lseek = lseek(file1, -2, SEEK_CUR)) != -1);

    free(c);
    close(file1);
    close(file2);
}