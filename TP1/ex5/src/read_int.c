#include "base.h"
#include "error_chk.h"

void read_int(const char* filepath, int pos) {
    int file1 = open(filepath, O_RDONLY);
    error_chk(file1);
    off_t nb_bytes = lseek(file1, pos, SEEK_CUR); 
    error_chk((int) nb_bytes);

    char* c = (char*) malloc(sizeof(char)); 
    malloc_error(c);
    ssize_t size_read = read(file1, c, 1); 
    error_chk(size_read);

    int64_t val = (int64_t) c; 

    printf("val = %"PRId64"\n", val);                                               

    free(c);
}