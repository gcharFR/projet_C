#include "compute_hash_value.h"
#include <string.h>

unsigned int compute_hash_value(char *input, unsigned char *md_value) {
   unsigned int md_len; // hash length
   EVP_MD_CTX *mdctx;   // hash context

   mdctx = EVP_MD_CTX_new();  // Initialize new context

   const EVP_MD *EVP_md5();   // Use EVP md5 function

   EVP_DigestInit_ex(mdctx, EVP_md5(), NULL);      // Initializes digest type
   EVP_DigestUpdate(mdctx, input, strlen(input));  // Add input to hash context
   EVP_DigestFinal_ex(mdctx, md_value, &md_len);   // Finalize hash context

   return md_len;

}
