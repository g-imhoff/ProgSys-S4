#ifndef RALER_H
#define RALER_H

void raler(const char* msg);

#define CHK(op)           \
    do {                  \
        if ((op) == -1) { \
            perror(#op);  \
            exit(1);      \
        }                 \
    } while (0)

#endif