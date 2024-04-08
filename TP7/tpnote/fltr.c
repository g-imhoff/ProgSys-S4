
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
/* vous n'avez normalement pas besoin de plus */

/* gestion des erreurs */
void raler (const char * msg)
{
    perror (msg);
    exit (EXIT_FAILURE);
}
#define CHECK(op) do { if ((op) == -1) raler (#op); } while (0)

void fltr(const char* entree, const char* rebut, const char* sortie) {
    int tube12[2], tube23[2];
    CHECK(pipe(tube12));
    CHECK(pipe(tube23));

    int fd_entree = open(entree, O_RDONLY);
    CHECK(fd_entree);
    int fd_rebut = open(rebut, O_WRONLY | O_CREAT, 0666);
    CHECK(fd_rebut);
    int fd_sortie = open(sortie, O_WRONLY | O_CREAT, 0666);
    CHECK(fd_sortie);


    switch (fork()) {
        case -1 :
            raler("Erreur lors du premier fork");
            break; 
        case 0 : 
            CHECK(close(tube12[0]));
            CHECK(dup2(fd_entree, STDIN_FILENO));
            CHECK(close(fd_entree));
            CHECK(dup2(tube12[1], STDOUT_FILENO));
            CHECK(close(tube12[1]));
            
            execlp("tr", "tr", ".#", "01", NULL);
            break;
    }

    CHECK(close(fd_entree));
    CHECK(close(tube12[1]));

    switch (fork()) {
        case -1 : 
            raler("Erreur lors du deuxième fork");
            break;
        case 0 : 
            //CHECK(close(tube23[0]));
            CHECK(dup2(tube23[1], STDOUT_FILENO));
            CHECK(close(tube23[1]));
            CHECK(dup2(tube12[0], STDIN_FILENO));

            char tab[8];
            ssize_t bytesRead;
            while ((bytesRead = read(STDIN_FILENO, tab, sizeof(tab))) > 0) {
                if (tab[0] == tab[6]) {
                    CHECK(write(fd_rebut, tab, 8));
                } else { 
                    printf("%s", tab);
                }
            }

            CHECK(bytesRead);

            break;
    }

    CHECK(close(tube12[0]));
    CHECK(close(fd_rebut));

    switch (fork()) {
        case -1 : 
            raler("Erreur lors du troisième fork");
            break;
        case 0 : 
            CHECK(dup2(fd_sortie, STDOUT_FILENO));
            //CHECK(close(tube23[1]));
            CHECK(dup2(tube23[0], STDIN_FILENO));
            CHECK(close(tube23[0]));

            execlp("cat", "cat", "-n", NULL); 
            break;
    }

}

int main (int argc, char * argv [])
{
    if (argc != 4)
    {
        fprintf (stderr, "Usage: %s entree rebut sortie\n", argv[0]);
        exit (EXIT_FAILURE);
    }
    /*
      argv[1] : nom du fichier entree
      argv[2] : nom du fichier rebut
      argv[3] : nom du fichier sortie
    */

    /* à vous d'écrire le reste */

    fltr(argv[1], argv[2], argv[3]);
}
