#include "base.h"
#include "error_chk.h"
#include "chercher_chaine.h"

bool recherche_fichier(const char* chaine_find, const char* filepath) {
    bool validite = false;

    int file1 = open(filepath, O_RDONLY);
    error_chk(file1);

    char* buffer = (char*)malloc(sizeof(char));
    int i = 0;
    int len_chaine_find = strlen(chaine_find);
    while (read(file1, buffer, 1) == 1 && !validite) {
        if (*buffer == chaine_find[i]) {
            i++;
        } else {
            i = 0;
        }

        if (i == len_chaine_find) {
            validite = true;
        }
    }

    close(file1);
    free(buffer);
    return validite;
}

void chercher_chaine(const char* chaine_find, const char* folder_path) {
    DIR* dir = opendir(folder_path);
    ifnull(dir);
    struct dirent* item;

    while ((item = readdir(dir)) != NULL) {
        ifnull(item);

        if (item->d_name[0] != '.') {
            struct stat* st = (struct stat*)malloc(sizeof(struct stat));
            malloc_chk(st);

            char full_path[PATH_MAX];
            int fullpath_chk = snprintf(full_path, sizeof(full_path), "%s/%s",
                                        folder_path, item->d_name);
            error_chk(fullpath_chk);

            int stat_chk = stat(full_path, st);
            error_chk(stat_chk);

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
    closedir(dir);
}