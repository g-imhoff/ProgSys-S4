#include "../header/base.h"
#include "../header/fork3.h"
#include "../header/error_chk.h"

void fork3(const char* filepath) {
    pid_t pid = fork();
    error_chk(pid);

    int file = open(filepath, O_RDONLY);
    error_chk(file);

    char buffer;

    ssize_t readsize = read(file, &buffer, 1);
    error_chk(readsize);

    int nbr_char_lu = (int)readsize;
    while (readsize > 0) {
        ssize_t sortie_standard_write = write(STDOUT_FILENO, &buffer, 1);
        error_chk((int)sortie_standard_write);
        readsize = read(file, &buffer, 1);
        error_chk(readsize);
        nbr_char_lu++;
    }

    // printf("Le nombre de char lu : %d", nbr_char_lu);
}