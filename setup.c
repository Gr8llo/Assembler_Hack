#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setup.h"

#define true 1
#define false 0

char *setup (char *inputFile){
    // to not modify original input -> !!C vs c++
    char fileName[strlen(inputFile)+1];
    strcpy(fileName, inputFile);

    if(!checkExtension(fileName)) {
        fprintf(stderr, "Invalid extension ");
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

    char *fileOutSrc = (char *)malloc(strlen(fileName) + strlen(fileExtension) + 1);

    if (fileOutSrc == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    } //check memory allocation

    //create file name with extension
    strcat(strcpy(fileOutSrc, fileName), fileExtension);
    return fileOutSrc;
}

int checkExtension(char *fileName) {
    int i=0;
    while(fileName[i] != '.' && fileName[i] != '\0') {
        i++;
    }
    if(fileName[i+4] == '\0'  && strncmp(&fileName[i+1], "asm", 3) == 0) return true;
    else return false;
}
