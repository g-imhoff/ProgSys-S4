#include "cp_std.h"
#include "base.h"
#include "error_chk.h"

void cp_std(const char *file1, const char *file2) {
  FILE *f1 = fopen(file1, "r");
  error_chk_file(f1);
  FILE *f2 = fopen(file2, "w");
  error_chk_file(f2);

  char buffer;
  while (fread(&buffer, sizeof(char), 1, f1) >= 1) {
    size_t nbr_bytes_write = fwrite(&buffer, sizeof(char), 1, f2);
    error_chk(nbr_bytes_write);
  }

  fclose(f1);
  fclose(f2);
}