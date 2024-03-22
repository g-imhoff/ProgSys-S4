#include "base.h"
#include "chercher_chaine.h"

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

bool recherche_fichier(const char* chaine_find, const char* filepath) {
    bool validite = false;

    int file1 = open(filepath, O_RDONLY);
    raler("Erreur lors de l'ouverture du fichier1", file1);

    char* buffer = (char*)malloc(sizeof(char));
    raler_null("Erreur lors de l'allocation pour le buffer", (void*)buffer);
    int i = 0;
    size_t len_chaine_find = strlen(chaine_find);

    ssize_t nbr_bytes_read;
    while ((nbr_bytes_read = read(file1, buffer, 1)) == 1 && !validite) {
        raler("Erreur lors de la lecture", (int)nbr_bytes_read);
        if (*buffer == chaine_find[i]) {
            i++;
        } else {
            i = 0;
        }

        if (i == (int)len_chaine_find) {
            validite = true;
        }
    }

    close(file1);
    free(buffer);
    return validite;
}

void chercher_chaine(const char* chaine_find, const char* folder_path) {
    DIR* dir = opendir(folder_path);
    raler_null("Erreur lors de l'ouverture du dossier", (void*)dir);
    struct dirent* item;

    while ((item = readdir(dir)) != NULL) {
        raler_null("Erreur lors du readdir", (void*)item);

        if (item->d_name[0] != '.') {
            struct stat* st = (struct stat*)malloc(sizeof(struct stat));
            raler_null("Erreur lors du stat", st);

            char full_path[PATH_MAX];
            int fullpath_chk = snprintf(full_path, sizeof(full_path), "%s/%s",
                                        folder_path, item->d_name);
            raler("Erreur lors de la création de full_path", fullpath_chk);

            int stat_chk = stat(full_path, st);
            raler("Erreur lors de stat", stat_chk);

            if (S_ISDIR(st->st_mode)) {
                chercher_chaine(chaine_find, full_path);
            } else {
                if (recherche_fichier(chaine_find, full_path)) {
                    printf("%s\n", full_path);
                }
            }
            free(st);
        }
    }
    int closing_directory = closedir(dir);
    raler("Erreur lors de la fermeture du dossier", closing_directory);
}