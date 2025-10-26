#include "generate_mode.h"
#include "compute_hash_value.h"
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int generate_mode(FILE *dictionaryFile, FILE *PHTfile) {

   printf("Start reading the dictionary file\n");

   #ifdef DEBUG
      printf("[DEBUG] Nota Bene: strings are expected to be <= %lu characters long\n",
             MAXSTRINGLENGTH * sizeof(char));
   #endif

   char *current_string = malloc((MAXSTRINGLENGTH + 2) * sizeof(char));
   // Buffer to read the strings in the dictionary file
   // The newline character and terminating null byte will be initially
   // included, hence we have to foresee 2 additional characters for the storage
   unsigned long current_line = 1;
   // Line to be read in the dictionary file, starting at 1
   unsigned char md_value[EVP_MAX_MD_SIZE];
   // Buffer to store the hash values
   unsigned int hash_length;
   // Hash length in md_value

   // Read strings one by one, line by line in dictionaryFile:
   while (fgets(current_string, MAXSTRINGLENGTH + 2, dictionaryFile) != NULL) {

      // We could read one line!
      if (current_string[strlen(current_string)-1] != '\n') {
         printf("ERROR: One string on line %lu of the dictionary file is more than %lu characters long, please rebuild with a greater MAXSTRINGLENGTH value\n",
                current_line,
                MAXSTRINGLENGTH * sizeof(char));
         fclose(dictionaryFile);
         fclose(PHTfile);
         return 3;
      }
      else {
         // Let's remove the trailing newline, that is not part of the actual string:
         current_string[strlen(current_string)-1] = '\0';
      }

      // We have now have our string in current_string and can compute
      // the corresponding hash value:
      hash_length = compute_hash_value(current_string, md_value);

      // We can now append first the string (and a newline) in PHTfile:
      if (fputs(current_string, PHTfile) == EOF || fputc('\n', PHTfile) == EOF) {
         printf("ERROR: A write operation on the precomputed hash table file failed");
         fclose(dictionaryFile);
         fclose(PHTfile);
         return 3;
      }
      #ifdef DEBUG
         printf("[DEBUG] (line %lu) string: \"%s\"",
                current_line,
                current_string);
      #endif

      // Then the corresponding hash value in hexadecimal format (and a newline, too):
      #ifdef DEBUG
         printf("\t--> MD5 hash value: 0x");
      #endif
      size_t i;
      for (i = 0; i < hash_length; i++) {
         if (fprintf(PHTfile, "%02x", md_value[i]) != 2) {
            printf("ERROR: A write operation on the precomputed hash table file failed");
            fclose(dictionaryFile);
            fclose(PHTfile);
            return 3;
         }
         #ifdef DEBUG
            printf("%02x", md_value[i]);
         #endif
      }
      if (fputc('\n', PHTfile) == EOF) {
         printf("ERROR: A write operation on the precomputed hash table file failed");
         fclose(dictionaryFile);
         fclose(PHTfile);
         return 3;
      }
      #ifdef DEBUG
         printf("\n");
      #endif

      current_line++;
   }

   printf("Finished reading the dictionary file, %lu lines have been read\n", current_line - 1);

   fclose(dictionaryFile);
   fclose(PHTfile);
   return 0;

}