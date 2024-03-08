#include "base.h"
#include "error_chk.h"

void read_int(const char* filename, int pos) {
    int file = open(filename, O_RDONLY);
    error_chk(file);

    int error = lseek(file, pos-1, SEEK_SET);
    error_chk(error);

    int64_t value;
    int read_error = read(file, &value, sizeof(int64_t));
    error_chk(read_error);
    printf("value : %ld\n", value);
    close(file);
}