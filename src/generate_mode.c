#include "generate_mode.h"
#include "compute_hash_value.h"
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int generate_mode(FILE *dictionaryFile, FILE *PHTfile) {

   #ifdef DEBUG
      printf("[DEBUG] Nota Bene: passwords are expected to be <= %lu characters long\n",
             MAXPASSWORDLENGTH * sizeof(char));
   #endif

   char *currentPassword = malloc((MAXPASSWORDLENGTH + 2) * sizeof(char));
   // Buffer to read the passwords in the dictionary file
   // The newline character and terminating null byte will be initially
   // included, hence we have to foresee 2 additional characters for the storage
   unsigned long currentLine = 1;
   // Line to be read in the dictionary file, starting at 1
   unsigned char md_value[EVP_MAX_MD_SIZE];
   // Buffer to store the hash values
   unsigned int hashLength;
   // Hash length in md_value

   // Read passwords one by one, line by line in dictionaryFile:
   while (fgets(currentPassword, MAXPASSWORDLENGTH + 2, dictionaryFile) != NULL) {
      // We could read one line!
      if (currentPassword[strlen(currentPassword)-1] != '\n') {
         printf("ERROR: One password on line %lu of the dictionary file is more than %lu characters long, please rebuild with a greater MAXPASSWORDLENGTH value\n",
                currentLine,
                MAXPASSWORDLENGTH * sizeof(char));
         fclose(dictionaryFile);
         fclose(PHTfile);
         return 3;
      }
      else {
         // Let's remove the trailing newline, that is not part of the actual password:
         currentPassword[strlen(currentPassword)-1] = '\0';
      }
      // We have our password in currenPassword
      #ifdef DEBUG
         printf("[DEBUG] (line %lu) password: \"%s\"",
                currentLine,
                currentPassword);
      #endif
      // Let's calculate the corresponding hash:
      hashLength = compute_hash_value(currentPassword, md_value);
      size_t i;
      #ifdef DEBUG
         printf("\t--> MD5 hash value (in hex format): \"");
         for (i = 0; i < hashLength; i++) {
            printf("%02x", md_value[i]);  // prints 2 hex-values of hash per loop
         }
         printf("\"\n");
      #endif
      // We can now append first the password (and a newline) in PHTfile:
      if (fputs(currentPassword, PHTfile) == EOF || fputc('\n', PHTfile) == EOF) {
         printf("ERROR: A write operation on the precomputed hash table file failed");
         fclose(dictionaryFile);
         fclose(PHTfile);
         return 3;
      }
      // Then the RAW corresponding hash value (and a newline, too):
      for (i = 0; i < hashLength; i++) {
         if (fputc(md_value[i], PHTfile) == EOF) {
            printf("ERROR: A write operation on the precomputed hash table file failed");
            fclose(dictionaryFile);
            fclose(PHTfile);
            return 3;
         }
      }
      if (fputc('\n', PHTfile) ==  EOF) {
         printf("ERROR: A write operation on the precomputed hash table file failed");
         fclose(dictionaryFile);
         fclose(PHTfile);
         return 3;
      }

      currentLine++;
   }
   #ifdef DEBUG
      printf("[DEBUG] %lu lines of the dictionary file have been read\n", currentLine - 1);
   #endif

   fclose(dictionaryFile);
   fclose(PHTfile);
   return 0;

}