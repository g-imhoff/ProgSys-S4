#ifndef ERROR_CHK_H
#define ERROR_CHK_H

#include <errno.h>

void error_chk(int error_code);
void malloc_chk(void* item);
void ifnull(void* item);

#endif