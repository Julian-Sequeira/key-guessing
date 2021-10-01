#include "encrypt.h"
#include <openssl/evp.h>
#include <string.h>

char *encrypt(unsigned char *key, unsigned char *vector, unsigned char *text) {

    EVP_CIPHER_CTX ctx;

    // initialize a context with the relevant details
    // encrypt update sends the first 16 byte block and put it into the ciphertext pointer
    // encrypt final - get the last 16 byte block
    // this is because the data is 32bytes

    // This gives us 32 raw bytes
    // but we are given a hex formatted string
    // so we need to go and change the raw bytes into a hex formatted array

    // Makefile: openssl is in the usr/include and usr/lib
    // ldl


    // First we need to make sure the key is actually 128 bits (16 bytes), as per the question need
    unsigned int key_len = strlen(key);
    unsigned int diff = 16 - key_len;
    unsigned char proper_key[16];
    strncpy(proper_key, key, key_len - 1)  //strip the newline character here



}