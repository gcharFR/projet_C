#include <stdio.h>
#include <string.h>
#include "generate_mode.h"

#define DEBUG
// Activates additional displays

int main(int argc, char *argv[]) {

   if (argc == 4 && strcmp(argv[1], "G") == 0) {
      #ifdef DEBUG
         printf("Generate mode\n");
      #endif
      FILE *dictionary = fopen(argv[2], "r");
      // Whe should be able to open the dictionary file in read mode:
      if (dictionary == NULL) {
         printf("Dictionary file \"%s\" cannot be read, exiting\n", argv[2]);
         return 0;
      }
      FILE *PHT = fopen(argv[3], "a");
      // We should be able to open the PHT file in append mode
      if (PHT == NULL) {
         printf("Precomputed hash table file \"%s\" cannot be opened in append mode, exiting\n", argv[3]);
         return 2;
      }
      return generate_mode(dictionary, PHT);
   }
   else if (argc == 2 && strcmp(argv[1], "L") == 0) {
      #ifdef DEBUG
         printf("Lookup mode\n");
      #endif
   }
   else {
      printf("Usage :\n");
      printf("   precomputed_hash_table G <dictionary file> <precomputed hash table file>;\n");
      printf("      Reads clear text passwords in the first file (line by line), generates\n");
      printf("      the corresponding hash value, then appends at the end of the second file\n");
      printf("      two new lines, one with the password and one with the hash value\n");
      printf("\n");
      printf("   precomputed_hash_table L;\n");
      return 1;
   }

}