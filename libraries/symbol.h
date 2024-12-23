#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdio.h>
#include <stdlib.h>


int checkVariableLabel (FILE *fileIn);
void setupBaseVariable(FILE *fileIn);
void removeSpaces(char *str);
void removeFirstLastChar(char *str);
int strcmpSymbol(char *str1, char *str2);
int insertSymbol(FILE *symbolTable, char *name, int val);
int extractValue(char *name);




#endif //SYMBOL_H
