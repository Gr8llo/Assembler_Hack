#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libraries/setup.h"
#include "libraries/symbol.h"
#include "libraries/assembler.h"

#define MAX 2056  //!!!!Warning a lot of buffer for long comments

//Ho lasciato alcuni commenti in inglese(per abitudine) lungo il codice per giustificare alcune scelte
//Ho anche introdotto un controllo minimo per gli errori
//per una breve descrizione del progetto o per problemi con il download l'ho caricato anche su git hub https://github.com/Gr8llo/Assembler_Hack

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

    char line[MAX];
	char *binaryLine;

    if(!checkVariableLabel(fileIn)) return 1; //errors already specified in setup

    rewind(fileIn);
    while(fgets(line, MAX, fileIn) != NULL) {
      removeSpaces(line);
      char *commentStart = strstr(line, "//");
      if(commentStart != NULL) *commentStart = '\0';
      if (line[0] == '\0' || line[0] == '\n' || line[0] == '\r' || line[0] == '(') continue; //continue salta al prossimo ciclo

      if((binaryLine = asmToBin(line))!=NULL) {
          fputs(binaryLine, fileOut);
          fputc('\n', fileOut);
      }
      else break;
    }

    //NOT pass directly "string_value"  as a parameter, segmentation fault => only read

    //ending all
    fclose(fileIn);
    fclose(fileOut);
    free(fileOutSrc);
    free(binaryLine);
    return 0;
}
