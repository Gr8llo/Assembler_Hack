#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdio.h>
#include <stdlib.h>

char *asmToBin(char *codeLine);
void removeSpaces(char *str);

// A-instruction functions
void Ainstrcution(char *codeLine, char *binStr);
int checkVariableLabel (FILE *fileIn);
void setupBaseVariable(FILE *fileIn);
void removeFirstLastChar(char *str);
int strcmpSymbol(char *str1, char *str2);
int insertSymbol(FILE *symbolTable, char *name, int val);
void decToBin(char *number, char *binStr);

// C-instruction functions
void Cinstrcution(char *codeLine, char* binStr);

#endif