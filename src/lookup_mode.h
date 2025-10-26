#include <stdio.h>

int lookup_mode(FILE *PHTfile);
   // Loads the file and use its data to try to fetch and print on stdout
   //    a string corresponding to each hash value entered on stdin
   // Precondition:
   //    - PHTfile is opened in read mode
   // Postcondition:
   //    - PHTfile is closed