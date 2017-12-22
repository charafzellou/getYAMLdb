#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void menu1();
void dbconnect(char * result);
void mainMenu(char * dbName);
void sqlQueryF(char * dbPath, char * sqlQuery, int querySize);
int tableExist(char * dbPath, char * dbName);
void dataInsertion(char * dbPath, char * dbName, char * values);
int fileLen(FILE* pf);
char * tableCounterPlusplus( char * counter);
