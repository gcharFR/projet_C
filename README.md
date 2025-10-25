# projet C

## Objet
Générer des tables de correspondance chaîne - condensat (sur la base d'un
algorithme de hachage donné) à partir d'un dictionnaire, et s'en servir pour
tenter de retrouver rapidement la chaîne à l'origine d'un condensat donné.

## Prérequis
- Disposer d'une machine de type Unix avec le compilateur C gcc et GNU make
- Disposer des bibliothèques de développement et des fichiers d'en-tête pour
   la bibliothèque libcrypto du projet [++OpenSSL++](https://www.openssl.org/)
   - installation sous Debian grâce au paquet "libssl-dev" du dépôt standard
      public : `sudo apt install libssl-dev;`

## Compilation du programme
- Se déplacer dans le répertoire "src"
- Reparamétrer si besoin le programme en éditant le fichier "Makefile" :
   - mode DEBUG ou non
   - longueur maximale des mots de passe attendus
- Lancer les commandes suivantes :
   - `make`
   - `make build-clean`

## Utilisation du programme
- Syntaxe : cf. `precomputed_hash_table --help`
- Nota Bene : chaque mot de passe d'un fichier dictionnaire doit se terminer
     par un retour à la ligne
- Codes de retour :
   0 : succès (même si aucun hash n'a été généré)
   1 : syntaxe incorrecte
   2 : Le fichier destiné à la T3C en mode génération ne peut pas être ouvert
      en écriture ou créé ou donne lieu à une erreur d'écriture
   3 : Certains mots de passe sont trop longs compte tenu du paramétrage du programme (MAXPASSWORDLENGTH)

## Opportunités d'amélioration
