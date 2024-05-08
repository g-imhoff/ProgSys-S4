# TP9
## Exercice 1
1. la différence est sur la méthode d'attente du signal, dans le cas de l'attente active, on attend le signal dans une boucle infini, dans le cas de l'ecoute passive on utilise la primitive sigsuspend qui demande au noyau de mettre le processus en sommeil en attendant le signal
2. il faut eviter l'écoute active, car il monopolise des ressource (de processeurs et autres) pour ne rien faire ! 

## Exercice 2 
1. Car les fonctions appelées lors de la prise en compte d'un signal est une fonctions asynchrone et cela peux créer des problème de concurrence, il vaut mieux éviter au maximum de faire des choses dans la fonction appelante
2. Car il permet d'éviter des problème de concurence
3. Ce sont des sections qu'il faut généralement protéger des signal pour éviter de les perturber
4. Elle commence a la ligne 23 et fini au 32
5. Pour éviter que tout les autres signal perturbe le programme
6. Le signal ne sera pas pris en compte, par exemple si on met SIGINT dans le masque, lorsqu'on envoie le signal il n'est pas prit en compte.

## Exercice 4 
1. On ne peux pas modifier l'action de SIGKILL et SIGSTOP, en realiter on peux les modifier, mais cela est réserver au noyau, cela peux etre expliquer du au fait que ce sont des commande particulière et particulièrement puissante, utiliser dans certains cas lorsque c'est nécéssaire, ou aussi car cela pourrais créer des processus immortel.
