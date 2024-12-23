#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

#define INS_LEN 17 // INSTRUCITON_LENGTH -> 16 bit + '\0'
#define MAX 2056
#define true 1
#define false 0



void removeSpaces(char *str){
  if(str == NULL) return;

  int len = strlen(str);
  char tmp[len];
  int count = 0;
  for(int i = 0; i < len; i++){
  	if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\r') {
		tmp[count] = str[i];
       	count++;
   	}
  }
  tmp[count] = '\0';
  strcpy(str, tmp);
}

int strcmpSymbol(char *str1, char *str2){
	int count=0;
    while(str1[count]==str2[count]){
      count++;
    }
	if((str1[count]=='\t' && str2[count]=='\0') || (str2[count]=='\t' && str1[count]=='\0')) return 0;
    else return 1;
}

void setupBaseVariable(FILE *symbolTable){
  	for(int i = 0; i < 16; i++){
    	fprintf(symbolTable, "R%d\t%d\n", i, i);
  	}
    fputs("SCREEN\t16384\n", symbolTable);
    fputs("KBD\t25476\n", symbolTable);
    fputs("SP\t0\n", symbolTable);
    fputs("LCL\t1\n", symbolTable);
    fputs("ARG\t2\n", symbolTable);
    fputs("THIS\t3\n", symbolTable);
    fputs("THAT\t4\n", symbolTable);
}

void removeFirstLastChar(char *str){
  int len = strlen(str);
  str[0] = ' ';
  str[len-1] = ' ';
  removeSpaces(str);
}

int insertSymbol(FILE *symbolTable, char *name, int val){

	char symbol[MAX];
	int thereis = false;
	rewind(symbolTable);
	while(fgets(symbol, MAX, symbolTable) != NULL && thereis != true){
		if(strcmpSymbol(symbol, name)==0) thereis = true;
	}
  	if(!thereis){
		fprintf(symbolTable, "%s\t%d", name, val);
        fputs("\n", symbolTable);
	}
	return thereis;
}

int checkVariableLabel(FILE *fileIn){
	FILE *symbolTable = fopen("variableLabel.txt", "w+");
    //w+ = write + read = reset the write and read
    //r+ = read + write = no reset and write and read
    char line[MAX];
    int lineNum=0;
    //Labels
    while ((fgets(line, MAX, fileIn)) != NULL){
        removeSpaces(line);
        char *commentStart = strstr(line, "//");
        if(commentStart != NULL) *commentStart = '\0';
        if (line[0] != '\0' && line[0] != '\n' && line[0] != '\r' && line[0] != '(') lineNum++;
  		if(line[0] == '(') {
            removeFirstLastChar(line);
			insertSymbol(symbolTable, line, lineNum);
      	}
    }

    setupBaseVariable(symbolTable);
    rewind(fileIn);
    int val=16;
    while ((fgets(line, MAX, fileIn)) != NULL){
        removeSpaces(line);
    	if(strcmp(line, "@") == 0){
         	fprintf(stderr, "Invalid character after @\n");
          	return false;
		}

		if(line[0]=='@' && atoi(line+1) == 0 && line[1]!='0'){
            int len = strlen(line+1);
            if(insertSymbol(symbolTable, line+1, val)==false) val+=1;
        }
    }

    return true;
    fclose(symbolTable);
}


int extractValue(char *name){
  	FILE *symbolTable = fopen("variableLabel.txt", "r");
    char line[MAX];
	while(fgets(line, MAX, symbolTable) != NULL){
		if(strcmpSymbol(name, line)==0) break;
	}
    int count = 0;
   	while(line[count]!='\t') count++;
    return atoi(line+count+1);
}