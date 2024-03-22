#include "base.h"
#include "cp_sys.h"
#include "raler.h"

void cp_sys(const char* pathname1, const char* pathname2, int taille_buffer) {
    int file1 = open(pathname1, O_RDONLY);
    raler("N'arrive pas a ouvrir le fichier 1", file1);
    int file2 = open(pathname2, O_WRONLY | O_CREAT,
                     S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    raler("N'arrive pas a ouvrir le fichier 2", file2);

    char* buffer = (char*)malloc(taille_buffer * sizeof(char));
    raler_null("Le malloc a échouer", (void*)buffer);

    ssize_t nbr_bytes_read = 100;
    while ((nbr_bytes_read = read(file1, buffer, taille_buffer)) >= 1) {
        raler("Erreur de l'ecture", (int)nbr_bytes_read);
        ssize_t nbr_bytes_write = write(file2, buffer, nbr_bytes_read);
        raler("Erreur d'écriture", (int)nbr_bytes_write);
    }

    free(buffer);
    close(file1);
    close(file2);
}