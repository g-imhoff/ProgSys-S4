#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>

#define CHK(op)  do { if ((op) == -1)   { perror (#op); exit (1); }} while (0)

void raler(const char*msg)
{   
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{   
    (void)argc;   // pour passer la compilation : ligne à supprimer/remplacer
    (void)argv;   // pour passer la compilation : ligne à supprimer/remplacer
     /*
     Arguments optionnels :
      - argv[1] : nom du fichier entree
      - argv[2] : nom du fichier sortie
    */




   return 0;
}
