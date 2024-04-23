#include "../header/base.h"
#include "../header/ecoute.h"
#include "../header/raler.h"

volatile sig_atomic_t signal_recu = 0;

void f() {
    signal_recu = 1;
}

void ecoute_active() {
    struct sigaction sa;

    sa.sa_handler = f;
    sa.sa_flags = 0;

    CHK(sigaction(SIGUSR1, &sa, NULL));

    while (!signal_recu)
        ;

    CHK(write(STDOUT_FILENO, "Signal recu\n", 12));
}
