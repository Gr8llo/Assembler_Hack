#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assembler.h"
#include "symbol.h"

#define INS_LEN 17 // INSTRUCITON_LENGTH -> 16 bit + '\0'
#define MAX 2056
#define true 1
#define false 0

void decToBin(int num, char *binStr){
    for(int i = INS_LEN-2; i > 0; i--){
        binStr[i] = (num % 2) + '0';
        num = num / 2;
    }
}

void Ainstrcution(char *codeLine, char *binStr){
    if(atoi(codeLine+1) == 0 && codeLine[1]!='0') decToBin(extractValue(codeLine+1), binStr);
    else decToBin(atoi(codeLine+1), binStr);
    binStr[0] = '0';
}

void divideStr(char *codeLine, char *dest, char *comp, char *jump){
	int i=0, j=0;;
    //dest/comp
    while(codeLine[i]!= '\0' && codeLine[i]!='=' && codeLine[i]!=';'){
   		dest[i] = codeLine[i];
        i++;
        if(i>3){
          fprintf(stderr, "Wrong ISA for a C instruction\n");
          comp[0] = '\0';
          return;
        }
    }
    dest[i] = '\0';
    if(codeLine[i]!='='){
      strncpy(comp, dest, 3);
      dest[0] = '\0';
    }
    else {
   		i++;
    	while(codeLine[i]!= '\0' && codeLine[i]!=';'){
   			comp[j] = codeLine[i];
            i++; j++;
            if(j>3){
          		fprintf(stderr, "Wrong ISA for a C instruction\n");
          		comp[0] = '\0';
          		return;
        	}
    	}
        comp[j] = '\0';
    }

    if(codeLine[i]==';'){
      	i++; j=0;
      	while(codeLine[i]!= '\0'){
   			jump[j] = codeLine[i];
            i++; j++;
            if(j>3){
          		fprintf(stderr, "Wrong ISA for a C instruction\n");
          		comp[0] = '\0';
          		return;
        	}
    	}
        jump[j] = '\0';
	}
}

int destToBin(char *dest, char *binStr){
	//range 10->12
    //coded with if so i can detect errors, non the most efficent way but effective
    if (dest[0] == '\0') { // Nessuna destinazione
        binStr[10] = '0'; binStr[11] = '0'; binStr[12] = '0';
    } else if (strcmp(dest, "M") == 0) {
        binStr[10] = '0'; binStr[11] = '0'; binStr[12] = '1';
    } else if (strcmp(dest, "D") == 0) {
        binStr[10] = '0'; binStr[11] = '1'; binStr[12] = '0';
    } else if (strcmp(dest, "MD") == 0) {
        binStr[10] = '0'; binStr[11] = '1'; binStr[12] = '1';
    } else if (strcmp(dest, "A") == 0) {
        binStr[10] = '1'; binStr[11] = '0'; binStr[12] = '0';
    } else if (strcmp(dest, "AM") == 0) {
        binStr[10] = '1'; binStr[11] = '0'; binStr[12] = '1';
    } else if (strcmp(dest, "AD") == 0) {
        binStr[10] = '1'; binStr[11] = '1'; binStr[12] = '0';
    } else if (strcmp(dest, "AMD") == 0) {
        binStr[10] = '1'; binStr[11] = '1'; binStr[12] = '1';
    }
    else{
      printf("Wrong ISA for a C instruction(dest)\n");
      return false;
    }
    return true;
}

int compToBin(char *comp, char *binStr){
	binStr[3] = '0'; // a bit
    //4->9
    if (strcmp(comp, "0") == 0) {
        memcpy(&binStr[4], "101010", 6);
    } else if (strcmp(comp, "1") == 0) {
        memcpy(&binStr[4], "111111", 6);
    } else if (strcmp(comp, "-1") == 0) {
        memcpy(&binStr[4], "111010", 6);
    } else if (strcmp(comp, "D") == 0) {
        memcpy(&binStr[4], "001100", 6);
    } else if (strcmp(comp, "A") == 0) {
        memcpy(&binStr[4], "110000", 6);
    } else if (strcmp(comp, "!D") == 0) {
        memcpy(&binStr[4], "001101", 6);
    } else if (strcmp(comp, "!A") == 0) {
        memcpy(&binStr[4], "110001", 6);
    } else if (strcmp(comp, "-D") == 0) {
        memcpy(&binStr[4], "001111", 6);
    } else if (strcmp(comp, "-A") == 0) {
        memcpy(&binStr[4], "110011", 6);
    } else if (strcmp(comp, "D+1") == 0) {
        memcpy(&binStr[4], "011111", 6);
    } else if (strcmp(comp, "A+1") == 0) {
        memcpy(&binStr[4], "110111", 6);
    } else if (strcmp(comp, "D-1") == 0) {
        memcpy(&binStr[4], "001110", 6);
    } else if (strcmp(comp, "A-1") == 0) {
        memcpy(&binStr[4], "110010", 6);
    } else if (strcmp(comp, "D+A") == 0) {
        memcpy(&binStr[4], "000010", 6);
    } else if (strcmp(comp, "D-A") == 0) {
        memcpy(&binStr[4], "010011", 6);
    } else if (strcmp(comp, "A-D") == 0) {
        memcpy(&binStr[4], "000111", 6);
    } else if (strcmp(comp, "D&A") == 0) {
        memcpy(&binStr[4], "000000", 6);
    } else if (strcmp(comp, "D|A") == 0) {
        memcpy(&binStr[4], "010101", 6);
    } else if (strcmp(comp, "M") == 0) {
        memcpy(&binStr[4], "110000", 6);
        binStr[3] = '1';
    } else if (strcmp(comp, "!M") == 0) {
        memcpy(&binStr[4], "110001", 6);
        binStr[3] = '1';
    } else if (strcmp(comp, "-M") == 0) {
        memcpy(&binStr[4], "110011", 6);
        binStr[3] = '1';
    } else if (strcmp(comp, "M+1") == 0) {
        memcpy(&binStr[4], "110111", 6);
        binStr[3] = '1';
    } else if (strcmp(comp, "M-1") == 0) {
        memcpy(&binStr[4], "110010", 6);
        binStr[3] = '1';
    } else if (strcmp(comp, "D+M") == 0) {
        memcpy(&binStr[4], "000010", 6);
        binStr[3] = '1';
    } else if (strcmp(comp, "D-M") == 0) {
        memcpy(&binStr[4], "010011", 6);
        binStr[3] = '1';
    } else if (strcmp(comp, "M-D") == 0) {
        memcpy(&binStr[4], "000111", 6);
        binStr[3] = '1';
    } else if (strcmp(comp, "D&M") == 0) {
        memcpy(&binStr[4], "000000", 6);
        binStr[3] = '1';
    } else if (strcmp(comp, "D|M") == 0) {
        memcpy(&binStr[4], "010101", 6);
        binStr[3] = '1';
    } else{
      printf("Wrong ISA for a C instruction(comp)\n");
      return false;
    }
    return true;
    //with strcpy attention beacause i put \0 at the end don't switch in the Cinstruction function
    //so i decided to use memcpy that doesn't add \0 at the end but limit itself to just copy
}

int jumpToBin(char *jump, char *binStr){
    //range 13->15
	if (jump[0] == '\0') {
        binStr[13] = '0'; binStr[14] = '0'; binStr[15] = '0';
    } else if (strcmp(jump, "JGT") == 0) {
        binStr[13] = '0'; binStr[14] = '0'; binStr[15] = '1';
    } else if (strcmp(jump, "JEQ") == 0) {
        binStr[13] = '0'; binStr[14] = '1'; binStr[15] = '0';
    } else if (strcmp(jump, "JGE") == 0) {
        binStr[13] = '0'; binStr[14] = '1'; binStr[15] = '1';
    } else if (strcmp(jump, "JLT") == 0) {
        binStr[13] = '1'; binStr[14] = '0'; binStr[15] = '0';
    } else if (strcmp(jump, "JNE") == 0) {
        binStr[13] = '1'; binStr[14] = '0'; binStr[15] = '1';
    } else if (strcmp(jump, "JLE") == 0) {
        binStr[13] = '1'; binStr[14] = '1'; binStr[15] = '0';
    } else if (strcmp(jump, "JMP") == 0) {
        binStr[13] = '1'; binStr[14] = '1'; binStr[15] = '1';
    }
    else{
      printf("Wrong ISA for a C instruction(jump)\n");
      return false;
    }
    return true;
}

void Cinstruction(char *codeLine, char* binStr){
    char dest[4], comp[4], jump[4];
    dest[0] = '\0'; comp[0] = '\0'; jump[0] = '\0';
    divideStr(codeLine, dest, comp, jump);
    if(comp[0]=='\0') binStr = NULL;

    binStr[0] = '1'; binStr[1] = '1' ; binStr[2] = '1';
    if(!destToBin(dest, binStr) ||!compToBin(comp, binStr) || !jumpToBin(jump, binStr)) binStr = NULL;
}

char *asmToBin(char *codeLine){
 	char *binStr = (char *)malloc(INS_LEN);
    for(int i = 0; i < INS_LEN-1; i++) binStr[i] = '0';
   	binStr[INS_LEN-1] = '\0';
    if(codeLine == NULL) return NULL;

    if(codeLine[0]=='@'){
        Ainstrcution(codeLine, binStr);
    }
    else{
        Cinstruction(codeLine, binStr);
    }
    return binStr;
}

