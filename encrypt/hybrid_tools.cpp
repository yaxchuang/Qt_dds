#include <stdint.h>
#include "hybrid_tools.h"


float Encryption_CBC(BYTE *data, uint32_t byte_num, float key)
{
    AES_Init();

    uint32_t round;
    int expandKeyLen;
    float x_init = key, y_init = key;
    BYTE henon_sequence[byte_num]; 
    BYTE IV[keyLen];
    BYTE *current_data, *previous_data;

    size_t bias = 0;
    BYTE *block_ptr = &henon_sequence[0];

    // pad byte_num to byte_num to n * keyLen >= byte_num
    if(byte_num % keyLen) {
        round = (byte_num / keyLen + 1);
    }else {
        round = (byte_num / keyLen);
    }
    KEYS x[byte_num/4 + 4 + 2], y[byte_num/4 + 4 + 2];

    /* generate initial vector */
    x[0].henon_float = x_init;
    y[0].henon_float = y_init;

    // generate henon series
    for(size_t j = 0; j < byte_num/4 + 4 + 1; j++) {
        float xj = x[j].henon_float;
        x[j+1].henon_float = 1 - alpha * xj * xj + y[j].henon_float;
        y[j+1].henon_float = beta * xj; 
    }
    x_init = x[byte_num/4 + 4 + 1].henon_float;
    y_init = y[byte_num/4 + 4 + 1].henon_float;
    
    // adjust henon series
    /*
    for(size_t j = 0; j < num_byte_xy/4; j++) {
        x[j].henon_int ^= (x[j].henon_int << 10) & 0xFE000000;
        x[j].henon_int ^= (x[j].henon_int >> 7) & 0x01FF8000;
        y[j].henon_int ^= (y[j].henon_int << 10) & 0xFE000000;
        y[j].henon_int ^= (y[j].henon_int >> 7) & 0x01FF8000;
    }
    */
    // copy x, y series to henon_sequence
    memcpy(IV, (BYTE*)x + bias, keyLen/2);
    memcpy(IV + keyLen/2, (BYTE*)y + bias, keyLen/2);
    bias += keyLen/2;

    // key used to encrypt
#ifndef USE_HYBRID
    BYTE key_encryption[expanded_length(keyLen)] \
    = {0x32, 0xF2, 0x51, 0x09, 0x80, 0xEE, 0xA7, 0x0B, \
       0x01, 0xC0, 0xCF, 0xB4, 0x62, 0x04, 0x67, 0x5D };

#else //ifdef USE_HYBRID
    BYTE key_encryption[expanded_length(keyLen)];

    for (size_t i = 0; i < byte_num/keyLen; i++) {
        memcpy(block_ptr, ((BYTE*)x) + bias, keyLen/2);
        memcpy(block_ptr + keyLen/2, ((BYTE*)y) + bias, keyLen/2);
        block_ptr += keyLen;
        bias += keyLen/2;
    }
#endif

    previous_data = &IV[0];
    bias = 0;
    
    /* encrypt the block */ 
    for (size_t i = 0; i < round; i++) {
        current_data = ((BYTE*)data) + bias;
        block_ptr = &henon_sequence[0] + bias;

        /* xor data and block */
        xor_data(current_data, previous_data, keyLen);

        // copy x, y series to key
#ifdef USE_HYBRID
        memcpy(key_encryption, block_ptr, keyLen);
#endif
        // expand key(length keyLen) and store them to key_encryption
        expandKeyLen = AES_ExpandKey(key_encryption, keyLen);

        // encrypt block using expanded key_encryption
        AES_Encrypt(current_data, key_encryption, expandKeyLen);

        // set bias
        bias += keyLen;
        previous_data = current_data;
    }

    return y_init;
}

float Decryption_CBC(BYTE *data, uint32_t byte_num, float key)
{
    AES_Init();

    uint32_t round;
    int expandKeyLen;
    float x_init = key, y_init = key;
    BYTE henon_sequence[byte_num]; 
    BYTE IV[keyLen];
    BYTE *current_data, *previous_data;

    size_t bias = 0;
    BYTE *block_ptr = &henon_sequence[0];

    // pad byte_num to byte_num to n * keyLen >= byte_num
    if(byte_num % keyLen) {
        round = (byte_num / keyLen + 1);
    }else {
        round = (byte_num / keyLen);
    }

    KEYS x[byte_num/4 + 4 + 2], y[byte_num/4 + 4 + 2];


    /* generate initial vector */
    x[0].henon_float = x_init;
    y[0].henon_float = y_init;

    // generate henon series
    for(size_t i = 0; i < byte_num/4 + 4 + 1; i++) {
        float xi = x[i].henon_float;
        x[i+1].henon_float = 1 - alpha * xi * xi + y[i].henon_float;
        y[i+1].henon_float = beta * xi; 
    }
    x_init = x[byte_num/4 + 4 + 1].henon_float;
    y_init = y[byte_num/4 + 4 + 1].henon_float;
    
    // adjust henon series
    /*
    for(size_t j = 0; j < num_byte_xy/4; j++) {
        x[j].henon_int ^= (x[j].henon_int << 10) & 0xFE000000;
        x[j].henon_int ^= (x[j].henon_int >> 7) & 0x01FF8000;
        y[j].henon_int ^= (y[j].henon_int << 10) & 0xFE000000;
        y[j].henon_int ^= (y[j].henon_int >> 7) & 0x01FF8000;
    }
    */
    // copy x, y series to henon_sequence
    memcpy(IV, (BYTE*)x + bias, keyLen/2);
    memcpy(IV + keyLen/2, (BYTE*)y + bias, keyLen/2);
    bias += keyLen/2;

#ifndef USE_HYBRID
    // key used to encrypt
    BYTE key_encryption[expanded_length(keyLen)] \
    = {0x32, 0xF2, 0x51, 0x09, 0x80, 0xEE, 0xA7, 0x0B, \
       0x01, 0xC0, 0xCF, 0xB4, 0x62, 0x04, 0x67, 0x5D };


#else //ifdef USE_HYBRID
    BYTE key_encryption[expanded_length(keyLen)];

    for (size_t i = 0; i < byte_num/keyLen; i++) {
        memcpy(block_ptr, ((BYTE*)x) + bias, keyLen/2);
        memcpy(block_ptr + keyLen/2, ((BYTE*)y) + bias, keyLen/2);
        block_ptr += keyLen;
        bias += keyLen/2;
    }
    
#endif

    bias = byte_num - keyLen;
    
    /* encrypt the block */ 
    for (size_t i = 0; i < round; i++) {
        current_data = ((BYTE*)data) + bias;
        previous_data = current_data - keyLen;
        if(i == round-1) 
            previous_data = &IV[0];
        block_ptr = &henon_sequence[0] + bias;

#ifdef USE_HYBRID
        // copy x, y series to key
        memcpy(key_encryption, block_ptr, keyLen);
#endif

        // expand key(length keyLen) and store them to key_encryption
        expandKeyLen = AES_ExpandKey(key_encryption, keyLen);

        // encrypt block using expanded key_encryption
        AES_Decrypt(current_data, key_encryption, expandKeyLen);

        /* xor data and block */
        xor_data(current_data, previous_data, keyLen);

        // set bias
        bias -= keyLen;
    }

    return y_init;
}

float Encryption_CTR(BYTE *data, uint32_t byte_num, float key)
{
    AES_Init();

    BYTE block[byte_num];
    uint32_t round;
    int expandKeyLen;
    float x_init = key, y_init = key;

    // key used to encrypt
    BYTE key_encryption[expanded_length(keyLen)];

    KEYS x[keyLen/4+1], y[keyLen/4+1];

    // pad byte_num to byte_num to n * keyLen >= byte_num
    if(byte_num % keyLen) {
        //printf("Pad\n");
        round = (byte_num / keyLen + 1);
    }else {
        round = (byte_num / keyLen);
    }
    
    // encrypt the block
    for (size_t i = 0; i < round; i++)
    {
        //printf("Done i=%d\n", i);
        x[0].henon_float = x_init;
        y[0].henon_float = y_init;

        // generate henon series
        for(size_t j = 0; j < keyLen/4 + 1; j++) {
            //printf("Done j=%d\n", j);
            float xj =  x[j].henon_float;
            x[j+1].henon_float = 1 - alpha * xj * xj + y[j].henon_float;
            y[j+1].henon_float = beta * xj; 
            //printf("x=%f, y=%f\n", x[j].henon_float, y[j].henon_float);
        }
        x_init = x[keyLen/4 + 1].henon_float;
        y_init = y[keyLen/4 + 1].henon_float;

        // adjust henon series
        /*
        for(size_t j = 0; j < keyLen/4 + 1; j++) {
            x[j].henon_int ^= (x[j].henon_int << 10) & 0xFE000000;
            x[j].henon_int ^= (x[j].henon_int >> 7) & 0x01FF8000;
            y[j].henon_int ^= (y[j].henon_int << 10) & 0xFE000000;
            y[j].henon_int ^= (y[j].henon_int >> 7) & 0x01FF8000;
        }
        */

        // copy x series to key
        memcpy(key_encryption, x, keyLen);

        // copy y series to block
        memcpy(block + i * keyLen, y, keyLen);

        // expand key(length keyLen) and store them to key_encryption
        expandKeyLen = AES_ExpandKey(key_encryption, keyLen);

        // encrypt block using expanded key_encryption
        AES_Encrypt(block + i * keyLen, key_encryption, expandKeyLen);
    }

    // 2. xor encryption to data
    xor_data(data, &block[0], byte_num);

    return y_init;
}

smallnum Encrypt_key(smallnum key, smallnum e, smallnum n)
{
    uint32_t temp_key = swap_bit(key);
    return mod_power_smallnum(temp_key, e, n);
}

smallnum Decrypt_key(smallnum key_encrypted, smallnum d, smallnum n)
{
    uint32_t temp_key = (uint32_t)mod_power_smallnum(key_encrypted, d, n);
    KEYS a;
    a.henon_int = swap_bit(temp_key);
    return (smallnum) a.henon_int;
}

uint32_t swap_bit(uint32_t input)
{
    uint32_t a, b;
    uint32_t p1, p2;
    uint32_t x = 1;
    char* c = (char*) &x;
    
    // config p according to endianness
    if((int)*c) {
        // little endian
        p1 = 30, p2 = 31;
    } else{
        // big endian
        p1 = 0, p2 = 1;
    }
    
    // swap bits p1, p2
    a = (input >> p1) & 1;
    b = (input >> p2) & 1;
    x = a ^ b;
    x = (x << p1) | (x << p2);
    return input ^ x;
}

void xor_data(BYTE* dest, BYTE *src, size_t n_byte)
{
    uint32_t *dest_temp = (uint32_t*)dest;
    uint32_t *src_temp = (uint32_t*)src;

    for(size_t j = 0; j < (n_byte/4); j++) {
        *(dest_temp + j) ^= *(src_temp + j);
    }
}
