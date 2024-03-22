#include "base.h"
#include "my_stat.h"

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

void my_stat(const char* pathfile) {
    struct stat* s = (struct stat*)malloc(sizeof(struct stat));
    raler_null("Erreur du malloc stat", (void*)s);

    int chk_stat = stat(pathfile, s);
    raler("Erreur du stat", chk_stat);

    printf("UID : %d\nGID : %d\nFile size : %ld\n", s->st_uid, s->st_gid,
           s->st_size);
    if (S_ISDIR(s->st_mode)) {
        printf("Type : Répertoire\n");
    } else {
        printf("Type : Régulier\n");
    }

    printf("Mode : %o\n", s->st_mode & 0777);
    free(s);
}
