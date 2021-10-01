#include "encrypt.h"
#include <openssl/evp.h>
#include <string.h>

char *encrypt(unsigned char *key, unsigned char *vector, unsigned char *text) {

    

    // initialize a context with the relevant details
    // encrypt update sends the first 16 byte block and put it into the ciphertext pointer
    // encrypt final - get the last 16 byte block
    // this is because the data is 32bytes

    // This gives us 32 raw bytes
    // but we are given a hex formatted string
    // so we need to go and change the raw bytes into a hex formatted array

    // Makefile: openssl is in the usr/include and usr/lib


    // First we need to make sure the key is actually 128 bits (16 bytes), as per the question need
    // unsigned int key_len = strlen(key);
    // unsigned int diff = 16 - key_len;
    // unsigned char proper_key[16];
    // memset(proper_key, '')
    // strncpy(proper_key, key, key_len - 1)  //strip the newline character here

    // Store the result here
    unsigned char *result = malloc(sizeof(unsigned char) * 64));

    // First, let's make sure the key is actually 128 bits long
    unsigned int targetlen = 16;
    const unsigned char *rightpad = "################";
    unsigned int paddinglen = targetln - strlen(key);  // should be fine not to worry about a negative number here, as the questions assures all keys are <= 16 characters
    printf("[%s%*.*s]", key, paddinglen, paddinglen, rightpad);

    // Set up the context class that will handle everything for us - init encryption function, pass key and vector
    EVP_CIPHER_CTX ctx;
    EVP_CIPHER_CTX_init(&ctx);
    EVP_EncryptInit_ex(&ctx, EVP_aes_128_cbc(), NULL, key, vector);
}