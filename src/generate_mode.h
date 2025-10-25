#include <stdio.h>

int generate_mode(FILE *dictionaryFile, FILE *PHTfile);
   // Reads clear text passwords in the first file (line by line), generates the
   //    corresponding hash value, then appends at the end of the second file
   //    two new lines, one with the password and one with the hash value.
   // Preconditions:
   //    - dictionaryFile is opened in read mode
   //    - PHTfile is opened in append mode
   // Postcondition :
   //    - both files are closed