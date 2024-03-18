#ifndef FORK_3_H
#define FORK_3_H

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

void fork3(const char* filepath);

#endif