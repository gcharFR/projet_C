#include "generate_mode.h"
#include <openssl/evp.h>

int generate_mode(FILE *dictionaryFile, FILE *PHTfile) {

   char *currentPassword = malloc(MAXPASSWORDLENGTH*sizeof(char));

   currentPassword = fgets(currentPassword, MAXPASSWORDLENGTH, dictionaryFile);
   printf("%s", currentPassword);
   currentPassword = fgets(currentPassword, MAXPASSWORDLENGTH, dictionaryFile);
   printf("%s", currentPassword);
   currentPassword = fgets(currentPassword, MAXPASSWORDLENGTH, dictionaryFile);
   printf("%s", currentPassword);

   fclose(dictionaryFile);
   fclose(PHTfile);
   return 0;

}