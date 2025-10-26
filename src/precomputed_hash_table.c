#include <stdio.h>
#include <string.h>
#include "generate_mode.h"
#include "lookup_mode.h"

int main(int argc, char *argv[]) {

   if (argc == 4 && strcmp(argv[1], "G") == 0) {
      #ifdef DEBUG
         printf("[DEBUG] Generate mode\n");
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
   else if (argc == 3 && strcmp(argv[1], "L") == 0) {
      #ifdef DEBUG
         printf("[DEBUG] Lookup mode\n");
      #endif
      FILE *PHT = fopen(argv[2], "r");
      // We should be able to open the PHT file in read mode
      if (PHT == NULL) {
         printf("Precomputed hash table file \"%s\" cannot be read, exiting\n", argv[2]);
         return 0;
      }
      return lookup_mode(PHT);
   }
   else {
      printf("Usage :\n");
      printf("   precomputed_hash_table G <dictionary file> <precomputed hash table file>;\n");
      printf("      Reads strings in the first file (line by line), generates the corresponding \n");
      printf("      hash value, then appends at the end of the second file two new lines,\n");
      printf("      one with the string and one with the hash value\n");
      printf("\n");
      printf("   precomputed_hash_table L <precomputed hash table file>;\n");
      printf("      Loads the file and use its data to try to fetch and print on stdout\n");
      printf("      a string corresponding to each hash value entered on stdin\n");
      return 1;
   }

}