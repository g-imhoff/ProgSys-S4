#include "base.h"
#include "ls2.h"

void raler(const char* msg, int status) {
    if (status < 0) {
        perror(msg);
        exit(status);
    }
}

void raler_null(const char* msg, void* x) {
    if (x == NULL) {
        perror(msg);
        exit(-1);
    }
}

char* permString(mode_t mode) {
    char* perms = (char*)malloc(11 * sizeof(char));
    raler_null("Erreur lors du malloc pour les permissions", (void*)perms);
    perms[0] = (S_ISDIR(mode)) ? 'd' : '-';
    perms[1] = (mode & S_IRUSR) ? 'r' : '-';
    perms[2] = (mode & S_IWUSR) ? 'w' : '-';
    perms[3] = (mode & S_IXUSR) ? 'x' : '-';
    perms[4] = (mode & S_IRGRP) ? 'r' : '-';
    perms[5] = (mode & S_IWGRP) ? 'w' : '-';
    perms[6] = (mode & S_IXGRP) ? 'x' : '-';
    perms[7] = (mode & S_IROTH) ? 'r' : '-';
    perms[8] = (mode & S_IWOTH) ? 'w' : '-';
    perms[9] = (mode & S_IXOTH) ? 'x' : '-';
    perms[10] = '\0';
    return perms;
}

void ls2(void) {
    DIR* dir = opendir(".");
    raler_null("Erreur lors de l'ouverture du dossier", (void*)dir);
    struct dirent* item;
    while ((item = readdir(dir))) {
        raler_null("Erreur lors du readdir", (void*)item);

        if (item->d_name[0] != '.') {
            struct stat* st = (struct stat*)malloc(sizeof(struct stat));
            raler_null("Erreur lors du malloc pour stat", (void*)st);
            int chk = stat(item->d_name, st);
            raler("Erreur lors du stat", chk);

            char* perms = permString(st->st_mode);
            printf("%s %s\n", perms, item->d_name);
            free(st);
            free(perms);
        }
    }
    int closing_directory = closedir(dir);
    raler("Erreur lors de la fermeture du dossier", closing_directory);
}