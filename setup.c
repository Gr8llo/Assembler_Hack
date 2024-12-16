#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setup.h"

char *setup (char *inputFile){
    // to not modify original input -> !!C vs c++
    char fileName[strlen(inputFile)+1];
    strcpy(fileName, inputFile);

    if(!checkExtension(fileName)) {
        fprintf(stderr, "Invalid extension");
        return NULL;
    }//check extension

    char *fileExtension = ".hack";
    {
        int i=0;
        while (fileName[i] != '.') {
            i++;
        }
        fileName[i] = '\0';
    } //remove extension



}

int checkExtension(char *fileName) {
    int i=0;
    while(fileName[i] != '.' && fileName[i] != '\0') {
        i++;
    }
    if(fileName[i+4] == '\0'  && strncmp(&fileName[i+1], "asm", 3) == 0) return true;
    else return false;
}
