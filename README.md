# projet C

## Objet
Pour un algorithme de hachage donné (en l'occurrence [MD5](https://fr.wikipedia.org/wiki/MD5)) être capables de
retrouver rapidement (plus vite qu'en O(n), n étant le nombre de condensats
existant) la chaîne de caractères à l'origine d'un condensat donné.
Pour cela on se sert d'une table de correspondance chaîne - condensat
pré-calculée sur la base d'un dictionnaire de chaînes de caractères à fournir.

## Prérequis
- Disposer d'une machine de type Unix avec le compilateur C gcc, la bibliothèque
  standard C et GNU make
- Disposer des bibliothèques de développement et des fichiers d'en-tête pour
  la bibliothèque libcrypto du projet [**OpenSSL**](https://www.openssl.org/)
   - installation sous Debian grâce au paquet "libssl-dev" du dépôt standard
     public : `sudo apt install libssl-dev;`

## Compilation du programme
- Se déplacer dans le répertoire "src"
- Reparamétrer si besoin le programme en éditant le fichier "Makefile" :
   - mode DEBUG ou non
   - longueur maximale attendue des mots de passe et des condensats
- Lancer les commandes suivantes :
   - `make`
   - `make build-clean`

## Utilisation du programme
- Syntaxe :
   - `precomputed_hash_table G
                             <fichier dictionnaire>
                             <fichier de condensats pré-calculés>;`
     Lit des chaînes de caractères dans le dictionnaire (ligne par ligne),
     génère le condensat correspondant, puis concatène à la fin du deuxième
     fichier deux nouvelles lignes, une avec la chaîne de caractères et une
     avec le condensat
   - `precomputed_hash_table L
                             <fichier de condensats pré-calculés>;`
     Charge le fichier et se sert de ses données pour chercher à récupérer
     et afficher sur la sortie standard la chaîne de caractères correspondant
     à chaque condensat saisi sur l'entrée standard'
- Nota Bene : chaque mot de passe d'un fichier dictionnaire doit se terminer
  par un retour à la ligne
- Codes de retour :
   0 : succès (même si aucun hash n'a été généré ou n'a pu être lu)
   1 : syntaxe incorrecte
   2 : Le fichier destiné à la T3C en mode génération ne peut pas être ouvert
       en écriture ou créé ou donne lieu à une erreur d'écriture
   3 : Certaines chaînes de caractère sont trop longues compte tenu du
       paramétrage du programme (MAXSTRINGLENGTH)
   4 : Certains condensats sont trop longs compte tenu du paramétrage
       du programme (MAXHASHLENGTH)
   5 : format du fichier de condensats pré-calculés incorrect

## Opportunités d'amélioration
- Conteneuriser la compilation et l'exécution du programme de façon à avoir une
  portabilité d'exécution
