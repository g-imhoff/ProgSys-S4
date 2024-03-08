#include "base.h"
#include "error_chk.h"
#include "my_stat.h"

void my_stat(const char* pathfile) {
    struct stat* s = (struct stat*)malloc(sizeof(struct stat));
    malloc_chk(s);
    int chk = stat(pathfile, s);
    error_chk(chk);

    printf("UID : %d\nGID : %d\nFile size : %ld\n", s->st_uid, s->st_gid,
           s->st_size);
    if (S_ISDIR(s->st_mode)) {
        printf("Type : Répertoire\n");
    } else {
        printf("Type : Régulier\n");
    }

    printf("Mode : %o\n", s->st_mode & 0777);
}
