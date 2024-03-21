#include "cp_sys.h"
#include "base.h"

/**
 * @brief This function check if there is an error
 *
 * This function will check if the param is really an error code, and if it is,
 * will print an error message and stop the program with the error_code as
 * status param
 *
 * @param error_code This param contains the error code that will determine
 * which error it is
 */

void raler(const char* msg, int status) {
    if (status < 0) {
        perror(msg);
        exit(status);
    }
}

void cp_sys(const char* pathname1, const char* pathname2) {
    int file1 = open(pathname1, O_RDONLY);
    raler("Ne peux pas ouvrir le fichier1", file1);
    int file2 = open(pathname2, O_WRONLY | O_CREAT,
                     S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    raler("Ne peux pas ouvrir le fichier2", file2);
    char buffer;

    while (read(file1, &buffer, sizeof(char)) >= 1) {
        ssize_t nbr_bytes_write = write(file2, &buffer, 1);
        raler("erreur d'écriture", nbr_bytes_write);
    }

    close(file1);
    close(file2);
}