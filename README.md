Threat model: The attacker knows an example plaintext, corresponding ciphertext, and the IV used. The attacker also knows the key is an English word less than 16 chars long. The encryption was done using AES-128-CBC.
This is an example program to brute force guess the key used. The assignment forbids the use of openssl commands, so this involves digging into the internals of the commands a little bit. 

Bonus: getting a refresher on C!