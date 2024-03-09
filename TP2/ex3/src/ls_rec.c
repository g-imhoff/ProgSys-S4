#include "base.h"
#include "error_chk.h"
#include "ls_rec.h"

void ls_rec(const char* pathfolder) {
    DIR* dir = opendir(pathfolder);
    ifnull(dir);
    struct dirent* item;
    while ((item = readdir(dir))) {
        ifnull(item);

        if (item->d_name[0] != '.') {
            struct stat* st = (struct stat*)malloc(sizeof(struct stat));
            malloc_chk(st);

            char full_path[PATH_MAX];
            int fullpath_chk = snprintf(full_path, sizeof(full_path), "%s/%s",
                                        pathfolder, item->d_name);
            error_chk(fullpath_chk);

            int stat_chk = stat(full_path, st);
            error_chk(stat_chk);

            if (S_ISDIR(st->st_mode)) {
                printf("%s\n", full_path);
                ls_rec(full_path);
            } else {
                printf("%s\n", full_path);
            }
            free(st);
        }
    }

    closedir(dir);
}