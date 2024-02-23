#include "base.h"
#include "error_chk.h"
#include "cp_rev.h"

void cp_rev(const char* filepath1, const char* filepath2) {
    int file1 = open(filepath1, O_RDONLY);
    error_chk(file1);
    int file2 = open(filepath2, O_CREAT | O_WRONLY, 0666);
    error_chk(file2);

    off_t file_size = lseek(file1, -1, SEEK_END);
    error_chk(file_size);
    char* c = (char*)malloc(sizeof(char));

    do {
        read(file1, c, 1);
        write(file2, c, 1);
    } while (lseek(file1, -2, SEEK_CUR) != -1);

    free(c);
    close(file1);
    close(file2);
}