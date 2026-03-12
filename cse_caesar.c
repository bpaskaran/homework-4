#include "cse_caesar.h"
#include "strgPtr.h"

static int isUpper(char c){
    return c >= 'A' && c <= 'Z';
}

static int isLower(char c){
    return c >= 'a' && c <= 'z';
}

static int isDigit(char c){
    return c >= '0' && c <= '9';
}



int encryptCaesar(const char *plaintext, char *ciphertext, int key){

    if(plaintext == NULL || ciphertext == NULL)
        return -2;

    int capacity = strgLen(ciphertext);

    if(capacity < 7)
        return -1;

    int i = 0;
    int encoded = 0;

    while(plaintext[i] != '\0' && i < capacity - 7){

        char c = plaintext[i];

        if(isUpper(c)){
            int shift = (key + i) % 26;
            c = ((c - 'A' + shift) % 26) + 'A';
            encoded++;
        }

        else if(isLower(c)){
            int shift = (key + i) % 26;
            c = ((c - 'a' + shift) % 26) + 'a';
            encoded++;
        }

        else if(isDigit(c)){
            int shift = (key + 2*i) % 10;
            c = ((c - '0' + shift) % 10) + '0';
            encoded++;
        }

        ciphertext[i] = c;
        i++;
    }

    if(i + 7 > capacity)
        return -1;

    ciphertext[i++] = '_';
    ciphertext[i++] = '_';
    ciphertext[i++] = 'E';
    ciphertext[i++] = 'O';
    ciphertext[i++] = 'M';
    ciphertext[i++] = '_';
    ciphertext[i++] = '_';
    ciphertext[i] = '\0';

    return encoded;
}


/* decrypt */

int decryptCaesar(const char *ciphertext, char *plaintext, int key){

    if(ciphertext == NULL || plaintext == NULL)
        return -2;

    int plen = strgLen(plaintext);

    if(plen == 0)
        return 0;

    int i = 0;
    int decoded = 0;

    while(ciphertext[i] != '\0'){

        if(ciphertext[i]=='_' &&
           ciphertext[i+1]=='_' &&
           ciphertext[i+2]=='E' &&
           ciphertext[i+3]=='O' &&
           ciphertext[i+4]=='M' &&
           ciphertext[i+5]=='_' &&
           ciphertext[i+6]=='_'){
            break;
        }

        char c = ciphertext[i];

        if(isUpper(c)){
            int shift = (key + i) % 26;
            c = ((c - 'A' - shift + 26) % 26) + 'A';
            decoded++;
        }

        else if(isLower(c)){
            int shift = (key + i) % 26;
            c = ((c - 'a' - shift + 26) % 26) + 'a';
            decoded++;
        }

        else if(isDigit(c)){
            int shift = (key + 2*i) % 10;
            c = ((c - '0' - shift + 10) % 10) + '0';
            decoded++;
        }

        if(i < plen - 1)
            plaintext[i] = c;

        i++;
    }

    if(ciphertext[i] == '\0')
        return -1;

    if(i < plen)
        plaintext[i] = '\0';
    else
        plaintext[plen - 1] = '\0';

    return decoded;
}