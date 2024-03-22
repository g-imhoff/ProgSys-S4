#include "base.h"
#include "write_int.h"

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

void write_int(const char* filename, int pos, int64_t value) {
    char zero = '0';

    int file = open(filename, O_RDWR | O_CREAT, 0666);
    raler("Erreur lors de l'ouverture du fichier1", file);

    off_t error_lseek = lseek(file, pos, SEEK_SET);
    raler("Erreur lors du positionnement du pointeur", (int)error_lseek);

    char c;

    ssize_t nbr_bytes_read, nbr_bytes_write;
    if ((nbr_bytes_read = read(file, &c, 1)) == 0) {
        raler("Erreur lors de la lecture du fichier", (int)nbr_bytes_read);

        ssize_t test = lseek(file, 0, SEEK_END);
        raler("Erreur lors du lseek test", (int)test);

        int i = (int)test;
        while (i != pos - 1) {
            nbr_bytes_write = write(file, &zero, 1);
            raler("Erreur lors de l'écriture", nbr_bytes_write);

            i++;
        }
    }

    nbr_bytes_write = write(file, &value, sizeof(int64_t));
    raler("Erreur lors de l'écriture", nbr_bytes_write);

    close(file);
}