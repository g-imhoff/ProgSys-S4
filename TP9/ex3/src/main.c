#include "../header/base.h"
#include "../header/raler.h"

volatile sig_atomic_t signal_recu = 0;

void gestionnaire_signal() {
    signal_recu = 1;
}

int main() {
    struct sigaction sa;
    int compteur = 0;

    sa.sa_handler = gestionnaire_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    sigset_t mask, oldmask, empty;
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);

    sigprocmask(SIG_BLOCK, &mask, &oldmask);  // début de la section critique

    while (compteur != 5) {
        if (!signal_recu) {
            sigemptyset(&empty);
            sigsuspend(&empty);

            compteur++;
            printf("\nLe compteur est à : %d\n", compteur);
        }

        signal_recu = 0;
    }

    sigprocmask(SIG_SETMASK, &oldmask, NULL);  // fin de la section critique

    return EXIT_SUCCESS;
}
