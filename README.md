# projet C

## Prérequis
- Disposer des bibliothèques de développement et des fichiers d'en-tête pour
   libcrypto du projet OpenSSL, disponibles grâce au paquet Debian "libssl-dev"
   - installation : `sudo apt install libssl-dev;`

## Compilation du programme

## Utilisation du programme
- Syntaxe : cf. `precomputed_hash_table --help`
- Nota Bene : 100 caractères par mot de passe situé dans le dictionnaire sont
   lus au maximum
- Codes de retour :
   0 : succès (même si aucun hash n'a été généré')
   1 : arguments incorrects
   2 : Le fichier destiné à la T3C en mode génération ne peut pas être ouvert
      en écriture ou créé
