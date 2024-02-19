#include "base.h"
#include "error_chk.h"
#include "cp_std.h"

void cp_std(const char* file1, const char* file2) {
    FILE* f1 = fopen(file1, "r"); 
    error_chk_file(f1); 
    FILE* f2 = fopen(file2, "w"); 
    error_chk_file(f2); 

    char buffer[50000];
    size_t nbr_bytes_read = fread(buffer, 1, sizeof(buffer), f1); 
    error_chk(nbr_bytes_read); 
    buffer[nbr_bytes_read] = '\0';  
    fclose(f1);
    
    size_t nbr_bytes_write = fwrite(buffer, 1, nbr_bytes_read, f2); 
    error_chk(nbr_bytes_write);
    fclose(f2);
 
}