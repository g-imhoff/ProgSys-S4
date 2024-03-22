#include "ls1.h"
#include "base.h"

void raler(const char *msg, int status) {
  if (status < 0) {
    perror(msg);
    exit(status);
  }
}

void raler_null(const char *msg, void *x) {
  if (x == NULL) {
    perror(msg);
    exit(-1);
  }
}

void ls1(void) {
  DIR *dir = opendir(".");
  raler_null("Erreur lors de l'ouverture du dossier", (void *)dir);
  struct dirent *item;
  while ((item = readdir(dir))) {
    raler_null("Erreur lors du readdir", (void *)item);
    if (item->d_name[0] != '.') {
      printf("%s\n", item->d_name);
    }
  }
  int close_directory = closedir(dir);
  raler("Erreur lors de la fermeture du dossier", close_directory);
}