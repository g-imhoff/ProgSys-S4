#include "error_chk.h"
#include "base.h"

void error_chk(int error_code) {
  if (error_code < 0) {
    switch (error_code) {
    case EPERM:
      perror("Operation not permitted\n");
      break;
    case ENOENT:
      perror("No such file or directory\n");
      break;
    case ESRCH:
      perror("No such process\n");
      break;
    default:
      perror("Error");
      break;
    }
    exit(error_code);
  }
}

void error_chk_file(FILE *file) {
  if (file == NULL) {
    perror("Error opening input file");
    exit(EXIT_FAILURE);
  }
}

void malloc_chk(void *item) {
  if (item == NULL) {
    perror("Malloc failled");
    exit(EXIT_FAILURE);
  }
}

void ifnull(void *item) {
  if (item == NULL) {
    perror("Malloc failled");
    exit(EXIT_FAILURE);
  }
}
