#include "../header/base.h"
#include "../header/raler.h"

volatile sig_atomic_t signal_recu = 0;

void gestionnaire_signal(int signal) {
    signal_recu = signal;
}

int main() {
    struct sigaction sa;

    sa.sa_handler = gestionnaire_signal;
    CHK(sigemptyset(&sa.sa_mask));
    sa.sa_flags = 0;

    for (int i = 1; i <= 31; i++) {
        if (i != SIGKILL && i != SIGSTOP)
            CHK(sigaction(i, &sa, NULL));
    }

    sigset_t mask, oldmask, empty;
    CHK(sigemptyset(&mask));
    CHK(sigaddset(&mask, SIGINT));

    CHK(sigprocmask(SIG_BLOCK, &mask,
                    &oldmask));  // début de la section critique

    if (!signal_recu) {
        CHK(sigemptyset(&empty));
        sigsuspend(&empty);
    }

    psignal(signal_recu, NULL);

    CHK(sigprocmask(SIG_SETMASK, &oldmask,
                    NULL));  // fin de la section critique

    return EXIT_SUCCESS;
}
