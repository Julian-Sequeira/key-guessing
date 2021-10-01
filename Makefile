gcc -c -o encrypt.o encrypt.c -lcrypto
gcc -c -o check_cipher.o check_cipher.c
gcc -c -o main.o main.c
gcc -o keyguesser main.o encrypt.o check_cipher.o