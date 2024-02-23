#include "base.h"
#include "error_chk.h"
#include "cp_sys.h"

void cp_sys(const char* pathname1, const char* pathname2, int taille_buffer) {
    int file1 = open(pathname1, O_RDONLY);
    error_chk(file1);
    int file2 = open(pathname2, O_WRONLY | O_CREAT,
                     S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    error_chk(file2);

    char* buffer = (char*)malloc(taille_buffer * sizeof(char));

    ssize_t nbr_bytes_read = 100;
    while (nbr_bytes_read >= 1) {
        nbr_bytes_read = read(file1, buffer, taille_buffer);
        error_chk(nbr_bytes_read);
        ssize_t nbr_bytes_write = write(file2, buffer, nbr_bytes_read);
        error_chk(nbr_bytes_write);
    }

    free(buffer);
    close(file1);
    close(file2);
}