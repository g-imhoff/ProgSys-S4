#include "base.h"
#include "error_chk.h"
#include "write_int.h"

void write_int(const char* filename, int pos, int64_t value) {
    char zero = '0';

    int file = open(filename, O_RDWR | O_CREAT, 0666);
    error_chk(file);

    int error = lseek(file, pos, SEEK_SET);
    error_chk(error);
    char c;
    if (read(file, &c, 1) == 0) {
        int test = lseek(file, 0, SEEK_END);
        error_chk(test);
        int i = test;
        while (i != pos - 1) {
            write(file, &zero, 1);
            i++;
        }
    }

    int write_error = write(file, &value, sizeof(int64_t));
    error_chk(write_error);
    close(file);
}