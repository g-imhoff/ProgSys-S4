#include "base.h"
#include "error_chk.h"
#include "cp_rev.h"

void cp_rev(const char* filepath1, const char* filepath2) {
    int file1 = open(filepath1, O_RDONLY); 
    error_chk(file1);
    int file2 = open(filepath2, O_CREAT | O_WRONLY, 0666); 
    error_chk(file2);

    char buffer[50000]; 
    ssize_t nbr_bytes_read = read(file1, buffer, sizeof(buffer)); 
    error_chk(nbr_bytes_read);

    printf("%c %c %c", buffer[49999], buffer[49998], buffer[49997]);
    size_t one_slot_buffer_size = sizeof(buffer[0]);
    for (int i = (int) (nbr_bytes_read - 1); i >= 0; i--) {
        ssize_t nbr_bytes_write = write(file2, &buffer[i], one_slot_buffer_size);
        error_chk(nbr_bytes_write);
    }
    
}