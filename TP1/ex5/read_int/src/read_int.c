#include "base.h"

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

void read_int(const char* filename, int pos) {
    int file = open(filename, O_RDONLY);
    raler("Erreur lors de l'ouverture du fichier1", file);

    off_t error_lseek = lseek(file, pos - 1, SEEK_SET);
    raler("Erreur lors du positionnement du pointeur", (int)error_lseek);

    int64_t value;
    ssize_t read_error = read(file, &value, sizeof(int64_t));
    raler("Erreur lors de la lecture du fichier", (int)read_error);

    printf("value : %ld\n", value);

    close(file);
}