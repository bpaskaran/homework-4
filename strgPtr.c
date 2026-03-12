#include "strgPtr.h"


static int isUpper(char c){
    return c >= 'A' && c <= 'Z';
}

static int isLower(char c){
    return c >= 'a' && c <= 'z';
}

static int isLetter(char c){
    return isUpper(c) || isLower(c);
}

static int isDigit(char c){
    return c >= '0' && c <= '9';
}



int strgLen(const char *s){

    if(s == NULL)
        return -1;

    int i = 0;

    while(s[i] != '\0'){
        i++;
    }

    return i;
}


void strgCopy(const char *source, char *destination, size_t size){

    if(source == NULL || destination == NULL)
        return;

    if(size == 0)
        return;

    size_t i = 0;

    while(i < size - 1 && source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';
}



void strgChangeCase(char *s){

    if(s == NULL)
        return;

    int i = 0;

    while(s[i] != '\0'){

        if(isLetter(s[i])){

            int leftDigit = 0;
            int rightDigit = 0;

            if(i > 0 && isDigit(s[i-1]))
                leftDigit = 1;

            if(s[i+1] != '\0' && isDigit(s[i+1]))
                rightDigit = 1;

            if(!leftDigit && !rightDigit){

                if(isUpper(s[i]))
                    s[i] = s[i] + ('a' - 'A');
                else
                    s[i] = s[i] - ('a' - 'A');
            }
        }

        i++;
    }
}


int strgDiff(const char *s1, const char *s2){

    if(s1 == NULL || s2 == NULL)
        return -2;

    int i = 0;

    while(s1[i] != '\0' && s2[i] != '\0'){

        if(s1[i] != s2[i])
            return i;

        i++;
    }

    if(s1[i] == s2[i])
        return -1;

    return i;
}


void strgInterleave(const char *s1, const char *s2, char *d, size_t size){

    if(s1 == NULL || s2 == NULL || d == NULL)
        return;

    if(size == 0)
        return;

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while(k < size - 1){

        if(s1[i] != '\0'){
            d[k++] = s1[i++];
            if(k >= size - 1) break;
        }

        if(s2[j] != '\0'){
            d[k++] = s2[j++];
            if(k >= size - 1) break;
        }

        if(s1[i] == '\0' && s2[j] == '\0')
            break;
    }

    while(k < size - 1 && s1[i] != '\0'){
        d[k++] = s1[i++];
    }

    while(k < size - 1 && s2[j] != '\0'){
        d[k++] = s2[j++];
    }

    d[k] = '\0';
}



void strgReverseLetters(char *s){

    if(s == NULL)
        return;

    int len = strgLen(s);

    int left = 0;
    int right = len - 1;

    while(left < right){

        while(left < right && !isLetter(s[left]))
            left++;

        while(left < right && !isLetter(s[right]))
            right--;

        if(left < right){

            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            left++;
            right--;
        }
    }
}