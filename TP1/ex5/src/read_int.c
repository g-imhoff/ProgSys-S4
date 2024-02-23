#include "base.h"
#include "error_chk.h"

void read_int(const char* filepath, int pos) {
    int fd = open(filepath, O_RDONLY);
    error_chk(fd);
    int offset = lseek(fd, pos, SEEK_SET);
    error_chk(offset);

    uint64_t num;
    int ret = read(fd, &num, sizeof(uint64_t));
    error_chk(ret);
    printf("%" PRIu64 "\n", num);

    close(fd);
}

