#include "lookup_mode.h"
#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lookup_mode(FILE *PHTfile) {

   printf("Start loading the precomputed hash table file\n");

   #ifdef DEBUG
      printf("[DEBUG] Nota Bene: strings are expected to be <= %lu characters long\n",
             MAXSTRINGLENGTH * sizeof(char));
      printf("[DEBUG] Nota Bene: hash values are expected to be <= %lu characters long\n",
             MAXHASHLENGTH * sizeof(char));
   #endif

   char *current_string = malloc((MAXSTRINGLENGTH + 2) * sizeof(char));
   // Buffer to read the strings in PHTfile
   // The newline character and terminating null byte will be initially
   // included, hence we have to foresee 2 additional characters for the storage
   char *current_hash = malloc((MAXHASHLENGTH + 2) * sizeof(char));
   // Same for hash values
   unsigned long current_line = 1;
   // Line to be read in PHTfile, starting at 1
   node_t *binary_tree = NULL;
   // The binary search tree we will populate with string - hash value
   // associations we'll find in PHTfile

   // Read string - hash value associations one by one in PHTfile:
   while (fgets(current_string, MAXSTRINGLENGTH + 2, PHTfile) != NULL) {

      // We could read one string
      if (current_string[strlen(current_string)-1] != '\n') {
         printf("ERROR: One string on line %lu of the precomputed hash table file is more than %lu characters long, please rebuild with a greater MAXSTRINGLENGTH value\n",
                current_line,
                MAXSTRINGLENGTH * sizeof(char));
         fclose(PHTfile);
         return 3;
      }
      else
         // Let's remove the trailing newline, that is not part of the actual string:
         current_string[strlen(current_string)-1] = '\0';
      current_line++;

      // We have now have our string in current_string and can read the
      // corresponding hash value:
      if (fgets(current_hash, MAXHASHLENGTH + 2, PHTfile) == NULL) {
         printf("ERROR: An hash value is missing at the end of the precomputed hash table file\n");
         return 5;
      }
      // We could read one hash value
      if (current_hash[strlen(current_hash)-1] != '\n') {
         printf("ERROR: One hash value on line %lu of the precomputed hash table file is more than %lu characters long, please rebuild with a greater MAXHASHLENGTH value\n",
                current_line,
                MAXHASHLENGTH * sizeof(char));
         fclose(PHTfile);
         return 4;
      }
      else
         // Let's remove the trailing newline, that is not part of the actual string:
         current_hash[strlen(current_hash)-1] = '\0';
      current_line++;

      binary_tree = add(binary_tree, current_hash, current_string);
      #ifdef DEBUG
         printf("[DEBUG] ");
         display_tree(binary_tree);
      #endif
   }

   printf("Finished reading the precomputed hash table file, %lu string - hash value associations have been read\n", (current_line - 1) / 2);

   // We can close the precomputed hash table file as we won't need it anymore:
   fclose(PHTfile);

   do {
      // Display our prompt:
      printf("Please type an MD5 hash value in hexadecimal format: ");
      fflush(stdout);

      // Process it:
      if (fgets(current_hash, MAXHASHLENGTH + 2, stdin) == NULL) { // Get the hash value
         printf("\nEnd of file\n");
         break;
      }
      else if (current_hash[strlen(current_hash)-1] != '\n')
         printf("ERROR: This hash value is more than %lu characters long, please rebuild with a greater MAXHASHLENGTH value\n",
                MAXHASHLENGTH * sizeof(char));
      else {
         // Let's remove the trailing newline, that is not part of the actual string:
         current_hash[strlen(current_hash)-1] = '\0';
         char *result_string = lookup(binary_tree, current_hash);
         if (result_string == NULL)
            printf("\tNo string having this hash value has been found\n");
         else
            printf("\tThis string has this hash value: \"%s\"\n", result_string);
      }
   }
   while (1);

   delete_tree (binary_tree);
   free(current_hash);
   free(current_string);
   return 0;
}