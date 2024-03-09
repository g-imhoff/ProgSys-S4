#include "base.h"
#include "error_chk.h"
#include "ls2.h"

char* permString(mode_t mode) {
    char* perms = (char*)malloc(11 * sizeof(char));
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
    ifnull(dir);
    struct dirent* item;
    while ((item = readdir(dir))) {
        ifnull(item);

        if (item->d_name[0] != '.') {
            struct stat* st = (struct stat*)malloc(sizeof(struct stat));
            int chk = stat(item->d_name, st);
            error_chk(chk);

            char* perms = permString(st->st_mode);
            printf("%s %s\n", perms, item->d_name);
            free(st);
            free(perms);
        }
    }
    closedir(dir);
}