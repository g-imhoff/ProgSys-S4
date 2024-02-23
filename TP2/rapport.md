# TP2
## Exercice 1 
1. Les informations sur la structure stat est trouvable dans man 2 stat
2. l'attribut est st_mode et il faut utiliser l'opérateur &, de sorte a garder uniquement les 3 derniers octets correspondant au permission 
3. on peux les interpreter sous cette forme 
 - r = 1 0 0 
 - w = 0 1 0
 - x = 0 0 1 

et donc en fonction des permission nous aurons un nombre entre 0 et 7 exemple : 
- rwx-wxr-x = 111 011 101 = 2² + 2¹ + 2⁰ / 2¹ + 2⁰ / 2² + 2⁰ = 735 

4. nous avons la macro S_ISREG et S_ISDIR qui vérifie si ce sont des fichier ou des dossiers 

## Exercice 2 

1. 

2. Voici les différente constantes permettant d'accéder au différent bits 

mode & S_IRUSR vérifie que ce bits existe 100 000 000
mode & S_IWUSR vérifie que ce bits existe 010 000 000
mode & S_IXUSR vérifie que ce bits existe 001 000 000
mode & S_IRGRP vérifie que ce bits existe 000 100 000
mode & S_IWGRP vérifie que ce bits existe 000 010 000
mode & S_IXGRP vérifie que ce bits existe 000 001 000
mode & S_IROTH vérifie que ce bits existe 000 000 100
mode & S_IWOTH vérifie que ce bits existe 000 000 010
mode & S_IXOTH vérifie que ce bits existe 000 000 001
