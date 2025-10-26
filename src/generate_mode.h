#include <stdio.h>

int generate_mode(FILE *dictionaryFile, FILE *PHTfile);
   // Reads strings in the dictionary file (line by line), generates the
   //    corresponding MD5 hash value, then appends at the end of PHTfile
   //    two new lines, one with the string and one with the hash value
   //    in hexadecimal format.
   // Preconditions:
   //    - dictionaryFile is opened in read mode
   //    - PHTfile is opened in append mode
   // Postcondition:
   //    - Both files are closed