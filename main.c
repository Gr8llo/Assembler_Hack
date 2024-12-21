#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "setup.h"
#include "assembler.h"

#define MAX 60

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
    char line[MAX];
	char *binaryLine;

    if(!checkVariableLabel(fileIn)) return 1; //errors already specified in setup

    while(fgets(line, MAX, fileIn) != NULL) {
        if((binaryLine = asmToBin(line)) != NULL) {
        	fputs(binaryLine, fileOut);
        	fputs("\n", fileOut);
        }
    }

    //NOT pass directly "string_value"  as a parameter, segmentation fault => only read

    //ending all
    fclose(fileIn);
    fclose(fileOut);
    free(fileOutSrc);
    return 0;
}
