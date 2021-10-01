import os

iv = "aabbccddeeff00998877665544332211"
plaintext = "This is a top secret."
ciphertext = "764aa26b55a4da654df6b19e4bce00f4ed05e09346fb0e762583cb7da2ac93a2"

def rightpad(string):
    result = string
    while len(result) < 16:
        result += "#"
    return result

f = open("words.txt", "r")
for word in f:
    key = rightpad(word)
    os.system('openssl enc -aes-128-cbc -e -in plaintext.txt -out ciphertext.txt -K ' + key + ' -iv aabbccddeeff00998877665544332211')
    f2 = open("cipertext.txt", "r")
    if f2.read() == ciphertext:
        print(key)
        break
