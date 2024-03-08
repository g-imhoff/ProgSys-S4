#include "base.h"
#include "chercher_chaine.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        perror("Il doit y avoir 2 argument");
        exit(EXIT_FAILURE);
    }

    chercher_chaine(argv[1], argv[2]);

    return EXIT_SUCCESS;
}