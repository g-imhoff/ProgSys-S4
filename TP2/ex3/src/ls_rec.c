#include "base.h"
#include "ls_rec.h"

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

void ls_rec(const char* pathfolder) {
    DIR* dir = opendir(pathfolder);
    raler_null("Erreur lors de l'ouverture du dossier", (void*)dir);
    struct dirent* item;
    while ((item = readdir(dir))) {
        raler_null("Erreur lors du readdir", (void*)item);

        if (item->d_name[0] != '.') {
            struct stat* st = (struct stat*)malloc(sizeof(struct stat));
            raler_null("Erreur lors du malloc pour stat", (void*)st);

            char full_path[PATH_MAX];
            int fullpath_chk = snprintf(full_path, sizeof(full_path), "%s/%s",
                                        pathfolder, item->d_name);
            raler("Erreur lors de la création de full_path", fullpath_chk);

            int stat_chk = stat(full_path, st);
            raler("Erreur lors du stat", stat_chk);

            if (S_ISDIR(st->st_mode)) {
                printf("%s\n", full_path);
                ls_rec(full_path);
            } else {
                printf("%s\n", full_path);
            }
            free(st);
        }
    }

    int closing_directory = closedir(dir);
    raler("Erreur lors de la fermeture du dossier", closing_directory);
}