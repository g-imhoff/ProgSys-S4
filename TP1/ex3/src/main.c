#include "base.h"
#include <time.h>
#include "cp_sys.h"
#include "cp_std.h"

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Ce programme nécessite 4 arguments mais a reçu : %d\n", argc);
        exit(EXIT_FAILURE);
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int buffer_size = atoi(argv[3]);
    cp_sys(argv[1], argv[2], buffer_size);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Temps d'exécution : %f secondes\n", cpu_time_used);

    return EXIT_SUCCESS;
}
