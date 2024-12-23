#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdio.h>
#include <stdlib.h>

char *asmToBin(char *codeLine);
// A-instruction functions
void Ainstrcution(char *codeLine, char *binStr);
void decToBin(int num, char *binStr);

// C-instruction functions
void Cinstruction(char *codeLine, char* binStr);
void divideStr(char *codeLine, char *dest, char *comp, char *jump);
int destToBin(char *dest, char *binStr);
int compToBin(char *comp, char *binStr);
int jumpToBin(char *jump, char *binStr);

#endif