#include "../header/base.h"
#include "../header/ecoute.h"
#include "../header/raler.h"

volatile sig_atomic_t signal_recu = 0;

void gestionnaire_signal() {
    signal_recu = 1;
}

void ecoute_passive() {
    struct sigaction sa;
    sa.sa_handler = gestionnaire_signal;
    CHK(sigemptyset(&sa.sa_mask));
    sa.sa_flags = 0;
    CHK(sigaction(SIGUSR1, &sa, NULL));

    sigset_t new;
    CHK(sigemptyset(&new));

    if (!signal_recu) {
        sigsuspend(&new);
    }

    CHK(write(STDOUT_FILENO, "Signal recu\n", 12));
}
