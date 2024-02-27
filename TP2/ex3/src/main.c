#include "base.h"
#include "ls_rec.h"

int main(int argc, char** argv) {
    if(argc != 2) {
        perror("Il doit y avoir 1 argument");
        exit(EXIT_FAILURE);
    }
    
    ls_rec(argv[1]);
    return EXIT_SUCCESS;
}