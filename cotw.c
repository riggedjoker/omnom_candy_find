/*
author - communications director
*/
/**OM NOM**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT_SIZE 100
//imma eat omnom's candy muahahahahahahahahahaha
//hehehehhehehehehehehehehehehehehehehehehehhehehehehehehehehehhehehehehehehehhehehehe
//https://tenor.com/view/sad-om-nom-om-nom-stories-aww-depressed-gif-6401467070996764419 - when i stole his candy AHAHAHAHAHAHAHA
//encryption of flag.
void flag_encryption(char* inputString, char* key, size_t len){
    FILE *writeptr = NULL;
    writeptr = fopen("candy.enc", "wb");
    int keyLen = strlen(key);
    char encrypted[INPUT_SIZE];
    for (int i = 0; i<len; i++){
       encrypted[i] = inputString[i] ^ key[i % keyLen];  
    }

    for (int i = 0; i<len; i++){
        fprintf(writeptr, "%02x", encrypted[i]);
    }
    fclose(writeptr);
}

char* candy_locker(){
    static char candy_savior[32];
    //obfuscating the key so that it is not visible in ghidra.
    char encryption[] = {0x6f^0xAA, 0x6d^0xAA, 0x6e^0xAA, 0x6f^0xAA, 0x6d^0xAA, 0x00};
    int encLen = strlen(encryption);
    for(int i = 0; i<encLen; i++){
        candy_savior[i] = encryption[i] ^ 0xAA; // deobfuscating
    }
    return candy_savior;
}

int main(){
    //---OMNOM'S CANDY IS HERE HAHAHAHAHAHAHAHAHAHA---//
    //---LETS SEE IF YOU'RE ABLE TO GRAB IT FROM ME---//
    //---pingpongpongping--//
    FILE *fptr;
    char buffer[INPUT_SIZE];
    fptr = fopen("candy.txt", "rb");
    printf("You have to uhhh do the opposite. regards, omnom\n");
    if (fptr == NULL){
        exit(EXIT_FAILURE);
        return 0;
    }
    char* candy_unlock = candy_locker();
    fgets(buffer, sizeof(buffer), fptr);
    int len = strlen(buffer);
    flag_encryption(buffer, candy_unlock, len);// to test whether the flag is stored or not
    fclose(fptr);
    return 0;
}
