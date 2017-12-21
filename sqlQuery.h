#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void dbconnect(char * result);
void mainMenu(char * dbName);
void sqlQueryF(char * dbPath, char * sqlQuery, int querySize);
