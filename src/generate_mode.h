#ifndef GMODE
#define GMODE

#include <stdio.h>

#define MAXPASSWORDLENGTH 101

int generate_mode(FILE *dictionaryFile, FILE *PHTfile);
   // Precondition:
   //    dictionaryFile is opened in read mode
   //    PHTfile is opened in append mode
   // Postcondition :
   //    both files are closed

#endif