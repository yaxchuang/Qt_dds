#ifndef HYBRID_TOOLS_H
#define HYBRID_TOOLS_H
#include "rsa_tools.h"
#include "aes_tools.h"
#include "henon_tools.h"

#define keyLen 16 // AES-128 (16 bytes = 16*8 bits)
#define expanded_length(keylen) keylen * (14 + 1)


/*
static smallnum e = 1217;
static smallnum n = 2147615971;
static smallnum d = 1388241145;
*/
float Encryption_CTR(BYTE *data, uint32_t byte_num, float key);
float Encryption_CBC(BYTE *data, uint32_t byte_num, float key);
float Decryption_CBC(BYTE *data, uint32_t byte_num, float key);
smallnum Encrypt_key(smallnum key, smallnum e, smallnum n);
smallnum Decrypt_key(smallnum key_encrypted, smallnum d, smallnum n);
uint32_t swap_bit(uint32_t input);
void xor_data(BYTE *dest, BYTE *src, size_t n_byte);

#endif //HYBRID_TOOLS_H