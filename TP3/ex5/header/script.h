#ifndef SCRIPT_H
#define SCRIPT_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

void script(const char* username);

#endif