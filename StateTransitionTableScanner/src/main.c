/**
* Name: Umit Demirci
* Lab: Lab 5 State Transition Table Scanner
* Date: 10/12/19
**/

// Lab5
//  main.c (driver for a scanner test)
//
//  ASSUMES: Lecture 1, 2, 3, 4

#include "scanner.h"
#include <unistd.h>

int main(int argc, char** argv)
{
    TOKEN *token = NULL;



    freopen(argv[1], "r", stdin); // switch stdin to get the table from the config file

    TRANS_TABLE *transitionTable = scanInit();

    freopen(argv[2], "r", stdin); // switch stdin to read from the input file

    while ((token = getNextToken(transitionTable)) != NULL)
    {
        printToken(token);
        freeToken(&token);
        fflush(stdout);
    }
    printf("\n");
}