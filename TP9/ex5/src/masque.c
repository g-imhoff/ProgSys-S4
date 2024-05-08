#include "../header/base.h"
#include "../header/raler.h"

volatile sig_atomic_t signal_recu = 0;

void gestionnaire_signal(int signal) {
    signal_recu = signal;
}

void masque() {
    struct sigaction sa;

    sa.sa_handler = gestionnaire_signal;
    CHK(sigemptyset(&sa.sa_mask));
    sa.sa_flags = 0;

    CHK(sigaction(SIGINT, &sa, NULL));

    sigset_t mask, oldmask, empty;
    CHK(sigemptyset(&mask));
    CHK(sigaddset(&mask, SIGINT));

    CHK(sigprocmask(SIG_BLOCK, &mask, &oldmask));  // début de la section critique

    if (!signal_recu) {
        CHK(sigemptyset(&empty));
        sigsuspend(&empty);
    }

    printf("J'ai recu le signal SIGINT\n");
    
    CHK(sigprocmask(SIG_SETMASK, &oldmask, NULL));  // fin de la section critique

    while (sleep(3) != 0);

    sigset_t secondMask, oldSecondMask;
    CHK(sigemptyset(&secondMask));
    CHK(sigaddset(&secondMask, SIGINT));
    CHK(sigprocmask(SIG_BLOCK, &secondMask, &oldSecondMask));

    while (sleep(3) != 0);

    CHK(sigprocmask(SIG_SETMASK, &oldSecondMask, NULL));

    while (sleep(3) != 0);
}