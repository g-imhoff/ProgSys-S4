#include "base.h"
#include "cp_sys.h"

/** 
 * @brief This function check if there is an error
 * 
 * This function will check if the param is really an error code, and if it is, will print an error message
 * and stop the program with the error_code as status param 
 * 
 * @param error_code This param contains the error code that will determine which error it is 
*/

void error_chk(int error_code) {
    if(error_code < 0) {
        switch(error_code) {
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

void cp_sys(const char* pathname1, const char* pathname2) {
    int file1 = open(pathname1, O_RDONLY); 
    error_chk(file1); 
    int file2 = open(pathname2 , O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    error_chk(file2); 

    char buffer;

    while (read(file1, &buffer, sizeof(char)) >= 1) {
        ssize_t nbr_bytes_write = write(file2, &buffer, 1); 
        error_chk(nbr_bytes_write);
    }

    close(file1);
    close(file2);
    
}