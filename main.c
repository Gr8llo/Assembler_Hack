#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "setup.h"
#include "assembler.h"

#define true 1
#define false 0

int main(const int argc, char *argv[]) {

    //check number of arguments
    if(argc < 2) {
        fprintf(stderr, "Invalid number of arguments");
        return 1; //errore generico
    }

    char *fileOutSrc = setup(argv[1]);
    if(fileOutSrc == NULL) return 1; //errors already specified in setup

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

    //sistemare
    int maxLineLength = 60;
    char line[maxLineLength];

    char *binaryLine;

    while(fgets(line, maxLineLength, fileIn) != NULL) {
        binaryLine = asmToBin(line);
        fputs(binaryLine, fileOut);
        fputs("\n", fileOut);
    }
    //ending all
    fclose(fileIn);
    fclose(fileOut);
    free(fileOutSrc);
    return 0;
}
