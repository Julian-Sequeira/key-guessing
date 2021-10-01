This is an assignment for a Computer Security class.

Threat model: 
- The attacker knows an example plaintext, corresponding ciphertext, and the IV used. 
- Knows the key is an English word less than 16 chars long. 
- The encryption was done using AES-128-CBC.
- Wants to find the encryption key

This is an example program to brute force guess the key used. The assignment forbids the use of openssl commands, so this involves digging into the internals of the commands a little bit. 
