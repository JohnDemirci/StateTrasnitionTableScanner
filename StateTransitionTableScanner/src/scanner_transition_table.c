/**
* Name: Umit Demirci
* Lab: Lab 5 State Transition Table Scanner
* Date: 10/12/19
**/

//
// Lab5
// scanner_transition_table.c
//
// Assumes lectures: 1, 2, 3, 4

#include "scanner.h"

//
// clean up the token structure
//
void freeToken(TOKEN **token)
{
    if (*token == NULL)
        return;

    // TODO free the token value if necessary
    if ((*token)->type == IDENT)
    {
        if ((*token)->val.string != NULL)
        {
            free((*token)->val.string);
        }
    }
    free(*token);
    *token = NULL;
}

//
// print a token
//
void printToken(TOKEN *token)
{
    // TODO implement the function

}

//
// Check if a collected sequence of characters is a keyword.
// If it is a keyword, change its type and return true
// If it is not a keyword, update it as an identifier token and return False
// (to update as identifier, copy the string into the tokens value and update the token type)
//
bool updateIfKeyword(TOKEN *token, char *string)
{
// TODO Implement the function

    if (strcasecmp(string, "repeat") == 0)
        token->type = REPEAT;
    else if (strcasecmp(string, "print") == 0)
        token->type = PRINT;
    else
        return false;

    return true;


}

//
// read the config file (your file containing the transition table)
// use the config to set up the transition table struct
//

TRANS_TABLE *scanInit()
{
    TRANS_TABLE *returnTable = malloc(sizeof(TRANS_TABLE));

// TODO Implement the function'
    // allocating space for inputSymbol classes
    // created variables to read from the file
    // because when i tried &returnTable->numberOfsttaes it did not work
    size_t size = BUF_SIZE;
    // size_t bytes_read;

    char *my_string;
    char* item = malloc(sizeof(char)*BUF_SIZE);

    // my_string = malloc(sizeof(char)*BUF_SIZE); (getline already allocates space)
    getline (&my_string, &size, stdin);

    returnTable->numberOfStates = atoi(strsep(&my_string,","));
    returnTable->numberOfClasses = atoi(strsep(&my_string,","));


    getline (&my_string, &size, stdin);
    returnTable->inputSymbolClasses = malloc(returnTable->numberOfClasses* sizeof(char*));
    for (int i = 0; i < returnTable->numberOfClasses; i ++) {
        returnTable->inputSymbolClasses[i] = malloc(BUF_SIZE * sizeof(char));
        item = strsep(&my_string, ",");

        if (item != NULL) {
            strcpy(returnTable->inputSymbolClasses[i], item);
        }
    }
    returnTable->table = malloc(returnTable->numberOfStates* sizeof(char*));

    for (int i = 0; i < returnTable->numberOfStates; i++) {
        returnTable->table[i] = malloc(returnTable->numberOfClasses * sizeof(char));
        for (int j = 0; j < returnTable->numberOfClasses; ) {

            char p = getc(stdin);
            if (p != '\n' && p != ',')
            {
                returnTable->table[i][j] = p;
                printf("%c ", returnTable->table[i][j]);
                j++;
            }
        }
        printf("\n");
    }

//    for (int i = 0; i < returnTable->numberOfClasses; i++) {
//
//        for (int j = 0; j < returnTable->numberOfStates; j++)  {
//
//            printf("%c ", returnTable->table[i][j]);
//
//        }
//        printf("\n");
//    }





//    int john[2];
//    int i = 0;
//
// getting the nunber of classes and states and storing them to the john array
//    char* token = strtok(my_string, ",");
//    while (token != NULL) {
//        printf("%s\n", token);
//        john[i] = atoi(token);
//        i++;
//        token = strtok(NULL, ",");
//    }




    /*numberOfStates = atoi(token);
    token = strtok(NULL, ",")*/



    /*numberOfStates = token;
    token = strtok(NULL, ",");
    numberOfclasses = token;
    token = strtok(NULL, ",");*/


//    // sscanf(my_string, "%d %d", &numberOfStates, &numberOfclasses);
//    // putting the john array values tot he respective return table states and classes
//    returnTable->numberOfStates = john[0];
//    returnTable->numberOfClasses = john[1];
//    // allocating space for the imputsymbol classes
//    returnTable->inputSymbolClasses = malloc(returnTable->numberOfClasses* sizeof(char*));
//    // free up sapce
//    free(my_string);
//    // reading the line
//    bytes_read = getline (&my_string, BUF_SIZE, stdin);
//    puts(my_string);
//
//    for (int i = 0; i < john[0]; i++) {
//        bytes_read = getline (&my_string, BUF_SIZE, stdin);
//        puts(my_string);
//    }
//
//
//    token = strtok(my_string, ",");
//    puts(my_string);
//    // creating a two dimentional array


/*    puts(my_string);
    my_string = NULL;
    bytes_read = getline (&my_string, &nbytes, stdin);*/


    return returnTable;
}

//
// find the index of the character class in transitionTable containing char c
//

int findClassIndex(TRANS_TABLE *transitionTable, char c) {
    int class = 0;

// TODO Implement the function
printf("%c", c);

/*for (int i = 0; i < transitionTable->numberOfClasses; i++) {

}*/
/*    for (int i = 0; i < transitionTable->numberOfClasses; i++) {
        p = strstr(transitionTable->inputSymbolClasses[i], &c);
        if (p) {
            printf("\nfound");
        } else {
            printf("\nnot found");
        }
    }*/


for (int i = 0; i < transitionTable->numberOfClasses; i++ ) {
    if (strchr(transitionTable->inputSymbolClasses[i], c ) != NULL ) {
        class = i;
        return  class;
    }
}

return class;
}

//
// reads characters from stdin to create the next token
// uses the transition table to drive the state machine
//

TOKEN *getNextToken(TRANS_TABLE *transitionTable)
{
    TOKEN *token = NULL;

/*    size_t size = BUF_SIZE;
    // size_t bytes_read;

    char *my_string;
    getline (&my_string, &size, stdin);
    puts(my_string);*/

// TODO Implement the functions textedit

int state = 0;

char ch;
ch = getc(stdin);
int classNumber = findClassIndex(transitionTable, ch);
printf("%d", classNumber);
char *buffer[BUF_SIZE] = {NULL};







/*while (1) {
    ch = getc(stdin);
    classNumber = findClassIndex(transitionTable, ch);*/

/*    switch (transitionTable->table[state][classNumber]) {
        case '0':
            state = 0;
            for (int i = 0; i < BUF_SIZE; i++) {
                if (buffer[i] == NULL ) {
                    strcpy(buffer[i], &ch);
                }
            }
            *//*if (strcmp(&transitionTable->table[state][classNumber], "a") == 0) {
                return myToken;
            }*//*
            break;
        case '1':
            state = 1;
            for (int i = 0; i < BUF_SIZE; i++) {
                if (buffer[i] == NULL ) {
                    strcpy(buffer[i], &ch);
                }
            }
            break;
        case '2':
            state = 2;
            for (int i = 0; i < BUF_SIZE; i++) {
                if (buffer[i] == NULL ) {
                    strcpy(buffer[i], &ch);
                }
            }
            break;
        case '3':
            state = 3;
            for (int i = 0; i < BUF_SIZE; i++) {
                if (buffer[i] == NULL ) {
                    strcpy(buffer[i], &ch);
                }
            }
            break;
        case '4':
            state = 4;
            for (int i = 0; i < BUF_SIZE; i++) {
                if (buffer[i] == NULL ) {
                    strcpy(buffer[i], &ch);
                }
            }
            break;
        case '5':
            state = 5;
            for (int i = 0; i < BUF_SIZE; i++) {
                if (buffer[i] == NULL ) {
                    strcpy(buffer[i], &ch);
                }
            }
            break;
        case '6':
            state = 6;
            for (int i = 0; i < BUF_SIZE; i++) {
                if (buffer[i] == NULL ) {
                    strcpy(buffer[i], &ch);
                }
            }
            break;
        case '7':
            state = 7;
            for (int i = 0; i < BUF_SIZE; i++) {
                if (buffer[i] == NULL ) {
                    strcpy(buffer[i], &ch);
                }
            }
            break;
        case '8':
            state = 8;
            for (int i = 0; i < BUF_SIZE; i++) {
                if (buffer[i] == NULL ) {
                    strcpy(buffer[i], &ch);
                }
            }
            break;
        case '9':
            state = 9;
            for (int i = 0; i < BUF_SIZE; i++) {
                if (buffer[i] == NULL ) {
                    strcpy(buffer[i], &ch);
                }
            }
            break;
        case 'a':
            ungetc(ch, stdin);
            return token;
        case 'e':
            puts("error");
    }*/








    return token;
}














