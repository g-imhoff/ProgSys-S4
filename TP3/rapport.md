# TP3 
## Exercice 1 
1. Il suffit de mettre les affichage après l'appel de la fonction waitpid, le processus attendra la fin du processus enfant puis effectura les action du processus parent. 
2. Comme dit dans man wait "The wait() system call suspends execution of the calling thread until one of its children terminates", il suffit de mettre un call wait(NULL) au début du programme, le programme parent continuera quand le processus enfant sera fini, le processus enfant lui ne s'arretera jamais car il n'a pas de processus enfant associé.
3. On peux ajouter un call exit(-1) pour le processus parent et utiliser la commande sleep(10) pour mettre un delai au processus enfant, de sorte à avoir un processus parent qui se termine avant l'enfant (et penser à enlever l'appel system waitpid qui pourrait nous faire échouer). 

## Exercice 2

## Exercice 3 
1. L'utilisation de execvp est simple, comme donner dans man exec int execvp(const char *file, char *const argv[]); dans file suffit de mettre le nom de la commande, en deuxieme argument il faut donner la variable argv mais sans les deux première argument et le faire finir par nul, dans notre cas si argv : 
argv = ["./run", "wc", "-l", "./src/run.c"], alors il faudra donner comme deuxieme argument :
arg = ["-l", "./src/run.c", NULL] 

2. La commande man 2 execve nous donne toutes les erreur possible chez la famille de fonctions exec(), sachant que le code 1 est égal a EPERM, le processus renverra 1 dans les cas ou nous aurons des problème de permission, man 2 execve nous donne plus d'information : 
EPERM  The filesystem is mounted nosuid, the user is not the superuser,and the file has the set-user-ID or set-group-ID bit set.
EPERM  The process is being traced, the user is not the  superuser  and
the file has the set-user-ID or set-group-ID bit set.
EPERM  A  "capability-dumb"  applications would not obtain the full set
of permitted capabilities granted by the executable  file.   See
capabilities(7).

