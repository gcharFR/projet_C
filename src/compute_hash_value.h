#include <openssl/evp.h>

unsigned int compute_hash_value(char *input, unsigned char *md_value);
// Computes the MD5 hash of the input in the table md_value, which should be
// at least EVP_MAX_MD_SIZE long; the return value is the actual hash length
