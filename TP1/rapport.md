# TP1
## Exercice 1 
1. 
2. Toutes les informations sur les constantes flags et mode_t on été obtenus par le biais du fichier man 2 open 

3. Dans notre cas, le programme s'arrête du à la fonction error_chk, sans cette fonction nous recevons un code erreur 255 

4. Après test, le code ce termine sans erreur, la copie s'effectue, mais le fichier dans le quelle nous coppions est créer sans aucune permission

## Exercice 2
1. J'ai trouver ces information dans man fopen
2. Il le créer avec comme permission 0666
3. EOF correspond au caractère mis à la fin d'un fichier, elle est donc présent à la fin d'un fichier 

## Exercice 3 
1. Voici les temps :

temps en ms pour cp_std : 
1156ms 

temps cp_sys : 

1 2m58,422s

8 22,917s 

16 10,909s 

256 738ms 

512 392ms 

1024 198ms 

4096 89ms

