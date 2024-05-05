#include "../header/base.h"
#include "../header/raler.h"

volatile sig_atomic_t signal_recu = 0;

void gestionnaire_signal() {
    signal_recu = 1;
}

int main() {
    struct sigaction sa;

    sa.sa_handler = gestionnaire_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    sigset_t mask, oldmask;
    sigfillset(&mask);
    sigdelset(&mask, SIGUSR1);
    sigdelset(&mask, SIGINT);

    sigprocmask(SIG_BLOCK, &mask, &oldmask);  // début de la section critique

    if (!signal_recu) {
        sigsuspend(&mask);
    }

    write(STDOUT_FILENO, "Signal recu\n", 12);

    sigprocmask(SIG_SETMASK, &oldmask, NULL);  // fin de la section critique

    return EXIT_SUCCESS;
}
