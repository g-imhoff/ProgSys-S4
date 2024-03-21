#include "error_chk.h"
#include "base.h"

void error_chk_file(FILE* file) {
    if (file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
}

void error_chk(int error_code) {
    if (error_code < 0) {
        switch (error_code) {
            case EPERM:
                printf("Operation not permitted\n");
                break;
            case ENOENT:
                printf("No such file or directory\n");
                break;
            case ESRCH:
                printf("No such process\n");
                break;
        }
        exit(error_code);
    }
}