#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// Need another function to check success

int main(int argc, char *argv[]) {

	// These values given in the question
	unsigned char iv[] = {0xaa,0xbb,0xcc,0xdd,0xee,0xff,0x00,0x99,0x88,0x77,0x66,0x55,0x44,0x33,0x22,0x11};
	unsigned char *plaintext = "This is a top secret.";
	unsigned char ciphertext[] = {0x76,0x4a,0xa2,0x6b,0x55,0xa4,0xda,0x65,0x4d,0xf6,0xb1,0x9e,0x4b,0xce,0x00f,0x4e,0xd0,0x5e,0x09,0x34,0x6f,0xb0,0xe7,0x62,0x58,0x3c,0xb7,0xda,0x2ac,0x93,0xa2}

    // Values to be filled
    unsigned char *cand_key;    // candidate keys taken from the wordlist
    unsigned char *ciphertest;  // ciphertext using the candidate key, to be checked against target
    unsigned int success = 0;

	// Open the wordlist
	FILE *wordlist = fopen("words.txt", "r");
	if (wordlist == NULL) {
		perror("No wordlist found");
		exit(1);
	}

	// Read one line at a time to get a candidate word
	// Gonna cheat a little and use the "getline" function
	// Not portable but much easier than dealing with buffers and trying to find a newline character - I would probably spend my entire allotted assignment time debugging that
    // So this must be run on a UNIX system!!
	char *cand_key = NULL;
	size_t len = 0;
	while(getline(&cand_key, &len, fp) != 1) {
		// candidate[strcspn(cand_key, "\r\n")] = 0;    // fget's strings are null terminated and we want to get rid of that (also want to get rid of any weird line break types that might be there hence the "\r")

        // Encrypt the plaintext using this candidate key
        ciphertest = encrypt(cand_key, iv, plaintext);

        // Check if the ciphertext generated matches the target cipher text
        if check_cipher(ciphertext, ciphertest) {
            printf("Success!!!");
            printf(cand_key);
            success = 1;
            break;
        }

        // Memory management at the end of the loop
        free(cand_key);
        free(ciphertest);
        len = 0;
	}

    fclose(wordlist);
    if (!success) {
        printf("Key was not found");
    }
}