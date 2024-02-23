#include "base.h"
#include "error_chk.h"
#include "ls1.h"

void ls1(void) {
    DIR* dir = opendir(".");
    ifnull(dir);
    struct dirent* item;
    while ((item = readdir(dir))) {
        ifnull(item); 
        if (item->d_name[0] != '.') {
            printf("%s\n", item->d_name);
        }
    }
}