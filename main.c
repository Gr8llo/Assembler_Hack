#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int checkExtension(char fileName[]) {
    int i=0;
    while(fileName[i] != '.' && fileName[i] != '\0') {
        i++;
    }
    if(fileName[i+4] == '\0'  && strncmp(&fileName[i+1], "asm", 3) == 0) return true;
    else return false;
}

int main(const int argc, char *argv[]) {

    //check number of arguments
    if(argc < 2) {
        fprintf(stderr, "Invalid number of arguments");
        return 1; //errore generico
    }

    char fileName[strlen(argv[1])+1];
    strcpy(fileName, argv[1]);


//    if(!checkExtension(fileName)) {
//        fprintf(stderr, "Invalid extension");
//        return 1;
//    }//check extension

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
        return 1;
    } //check memory allocation

    //create file name with extension
    strcat(strcpy(fileOutSrc, fileName), fileExtension);

    FILE *fileIn = fopen(argv[1], "r");
    if (fileIn == NULL) {
        fprintf(stderr, "File %s could not be opened\n", argv[1]);
        free(fileOutSrc);
        return 1;
    } //check memory allocation

    FILE *fileOut = fopen(fileOutSrc, "w");
    if (fileOut == NULL) {
        fprintf(stderr, "File %s could not be created\n", fileOutSrc);
        free(fileOutSrc);
        return 1;
    } //check memory allocation

    int maxLineLength = 60;
    char line[maxLineLength];
    char binaryLine[17] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0' };

    while(fgets(line, maxLineLength, fileIn) != NULL) {
        fputs(binaryLine, fileOut);
        fputs("\n", fileOut);
    }
    //ending all
    fclose(fileIn);
    fclose(fileOut);
    free(fileOutSrc);
    return 0;
}
