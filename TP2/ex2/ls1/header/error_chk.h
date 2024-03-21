#ifndef ERROR_CHK_H
#define ERROR_CHK_H

void error_chk(int error_code);
void error_chk_file(FILE *file);
void malloc_chk(void *item);
void ifnull(void *item);

#endif