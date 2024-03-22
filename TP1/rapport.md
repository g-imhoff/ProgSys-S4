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

2. le buffer est de taille 8192octets

## Exercice 4 
1. Pour positionner a la toute fin du fichier lseek(nom_du_fichier, 0, SEEK_END);

2. Pour faire reculer la tête de lecture lseek(nom_du_fichier, -1, SEEK_CUR); 

3. Dans mon code j'ai utiliser cette ligne de code  off_t file_size = lseek(file1, -1, SEEK_END);

file_size va contenir la taille en octet du fichier

On peux aussi parcourir tout le fichier et en determiner le nombre d'octet ? 

## Exercice 5 
1. Le programme renvoie une erreur 255

2. Le programme renvoie des nombres au hasard

3. Sachant que lseek(file, 0, SEEK_END) renvoie la longueur du fichier, on pourrais faire un test verifiant que la position n'est pas supérieur à cette fonction 

4. Comme demander dans l'énoncer il ajoute des 0 jusqu'a la position
