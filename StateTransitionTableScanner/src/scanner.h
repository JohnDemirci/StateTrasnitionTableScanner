// Lab5
//  scanner.h
//

/**
* Name: Umit Demirci
* Lab: Lab 5 State Transition Table Scanner
* Date: 10/12/19
**/

#ifndef __SCANNER_H
#define __SCANNER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

typedef enum
{
    INVALID = 0,
    IDENT,
    NUMBER, //1
    ASSIGNMENT,   //3
    SEMICOLON,    //4
    LPAREN,       //5
    RPAREN,       //6
    ADD_OP,       //7
    MULT_OP,      //8
    REPEAT,       //9
    PRINT,        //10
    END_OF_INPUT  //11
} TOKEN_TYPE;

typedef union token_value
{
    char *string;  // for identifiers
    double number; // for numbers
    char op;       // for multop, addop
                   // for all other token types, no value is needed
} TOKEN_VALUE;

typedef struct token
{
    TOKEN_TYPE type;
    TOKEN_VALUE val;
} TOKEN;

typedef struct
{
    int numberOfStates; // rows
    int numberOfClasses; // columns
    char **inputSymbolClasses;
    char **table;
} TRANS_TABLE;

TRANS_TABLE *scanInit();
bool updateTypeIfKeyword(TOKEN *token, char *string);
int findClassIndex(TRANS_TABLE *transitionTable, char c);
TOKEN* getNextToken(TRANS_TABLE *outputTable);
void printToken(TOKEN *);
void freeToken(TOKEN **);

#define BUF_SIZE 128
#define MAX_LINE_LENGTH 256

#endif