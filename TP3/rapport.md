# TP3 
## Exercice 1 
1. Il suffit de mettre les affichage après l'appel de la fonction waitpid, le processus attendra la fin du processus enfant puis effectura les action du processus parent. 
2. Comme dit dans man wait "The wait() system call suspends execution of the calling thread until one of its children terminates", il suffit de mettre un call wait(NULL) au début du programme, le programme parent continuera quand le processus enfant sera fini, le processus enfant lui ne s'arretera jamais car il n'a pas de processus enfant associé.
3. On peux ajouter un call exit(-1) pour le processus parent et utiliser la commande sleep(10) pour mettre un delai au processus enfant, de sorte à avoir un processus parent qui se termine avant l'enfant (et penser à enlever l'appel system waitpid qui pourrait nous faire échouer). 

## Exercice 2
