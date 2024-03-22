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

1. on pourrait peux être utiliser strcmp

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

## Exercice 3 

1. Pour gérer l'aspect récursif de l'affichage des fichiers dans les sous-répertoires il y deux cas, sois c'est une fichier et donc on affiche le chemin entier, si c'est un dossier on affiche le chemin, puis on fait un appel récursif avec le chemin comme arguments.
2. La taille du buffer doit être égale à PATH_MAX pour être sur que nous aurons un espace suffisant pour stocker le chemin du fichier/dossier.
3. On peux détécter les erreur en verifiant que ce que renvoie readdir est différent de null.
4. Dans mon cas, j'ai créer une fonction ifnull, qui vérifie si ce que renvoie readdir est différent de null, si c'est égale à nul ça affiche un message d'erreur et arrete le programme.

## Exercice 4 

1. Pour rechercher une chaine au sein du fichier, je vais lire le fichier 1 par 1, si à un moment donner, l'élément lu est égal au ieme élément dans chaine_find on incrémente i de 1, si il est différent on remet i = 0 et si i est égal a la longueur de chaine_find on arrete la boucle et on renvoie vrai, cela nous permet donc d'avoir un boolean qui nous dis si la chaine de caractère est contenu dans le fichier ou non 
