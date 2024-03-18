#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

bool magic_number_is_P5(char magic_number[3]) {
    bool validite = magic_number[0] == 'P' && magic_number[1] == '5';
    validite = validite && (magic_number[2] == '\n' || magic_number[2] == ' ' || magic_number[2] == '\t');
    return validite;
}

int convert_pgm(const char* filein, const char* fileout) {
    printf("%s %s\n", filein, fileout); 
    int file = open(filein, O_RDONLY);
    if (file == -1) {
        perror("open");
        return 1; // error on system call
    }

    char magic_number[3];

    if (read(file, &magic_number, 3) != 3) {
        perror("read");
        return 1; // error on system call
    }

    if (!magic_number_is_P5(magic_number)) {
        perror("magic number is not P5");
        return 2; // error on magic number
    }

    printf("magic number is P5\n");

    return 0; // success
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filein> <fileout>\n", argv[0]);
        return 1;
    }

    int error_code = convert_pgm(argv[1], argv[2]);
    
    if (error_code == 0) {
        printf("Conversion successful\n");
    } else if (error_code == 1) {
        printf("Error on system call\n");
    } else if (error_code == 2) {
        printf("Error on magic number\n");
    }

    return error_code;
}