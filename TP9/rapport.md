# TP9
## Exercice 1
1. la différence est sur la méthode d'attente du signal, dans le cas de l'attente active, on attend le signal dans une boucle infini, dans le cas de l'ecoute passive on utilise la primitive sigsuspend qui demande au noyau de mettre le processus en sommeil en attendant le signal
2. il faut eviter l'écoute active, car il monopolise des ressource (de processeurs et autres) pour ne rien faire ! 
