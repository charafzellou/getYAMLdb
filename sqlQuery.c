#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

int menu1(int argc, char ** argv) {
    char name[255];
    char choiceMenu1;

    do{
        printf("----   MENU   ----\n");
        printf("a.   connexion\n");
        printf("q.   quitter\n");
        scanf("%c", &choiceMenu1);
        fflush(stdin);
        system("cls");
        switch(choiceMenu1){
            case 'a':
                do{
                    dbconnect(name);
                    if ( !strcmp(name, "error") ){
                        printf("cette base n'existe pas X_X\n");
                    } else {
                        mainMenu(name);
                    }
                } while( !strcmp(name, "error") );
                break;
            case 'q':
                system("cls");
                printf("Bye");
                break;
            default:
                printf("option inconnue :/\n");
                Sleep(1000);
                system("cls");
        }
    }while ( choiceMenu1 != 'q' );

    return 0;
}

/**
*    function that ask the user to choose a database to connect to.
*    if the dataBase exist the name is saved in result
*    else if it doesn't exist the string "error" is saved in result.
*/
void dbconnect(char * result){
    char dbName[240];
    char dbRepertory[255] = "DataBases\\";
    int dbNameLength;
    FILE* dataBase;

    dbRepertory[11] = '\0';

    system("DIR/B/AD DataBases");
    printf("Entrer le nom de la base de donn%ce :\n  nom : ", 130);
    fgets(dbName, 240, stdin);
    dbNameLength = strlen(dbName);
    if ( dbNameLength < 240 ){
        dbName[dbNameLength - 1] = '\0';
    }
    fflush(stdin);
    system("cls");

    strcat(dbRepertory, dbName);
    strcat(dbRepertory, "\\params.yaml");
    dataBase = fopen(dbRepertory, "r");

    if ( dataBase != NULL){
        fclose(dataBase);
        strcpy(result, dbName);
    } else {
        strcpy(result, "error");
    }
}

void mainMenu(char * dbName){
    char paramsPath[255] = "DataBases\\";
    char dbPath[255];
    char charCheck;
    char sqlQuery[600];
    int querySize;
    FILE * dbParams;

    sqlQuery[0] = '\0';
    dbPath[0] = '\0';
    paramsPath[11] = '\0';
    strcat(paramsPath, dbName);
    strcpy(dbPath, dbName);
    strcat(paramsPath, "\\params.yaml");

    printf("Base de donn%ce : %s\n", 130, dbName);

    dbParams = fopen(paramsPath, "r");
    if ( dbParams != NULL){
        fseek(dbParams, 11, SEEK_SET);
        while ( !feof(dbParams) ){
            charCheck = fgetc(dbParams);
            if ( charCheck != ' '){
                printf("%c", charCheck);
            }
        }
        fclose(dbParams);
    } else {
        printf("Une erreur est survenue :/");
    }

    do {
        printf("\n requ%cte SQL (quit pour quitter): ", 136);
        fgets(sqlQuery, 600, stdin);
        querySize = strlen(sqlQuery);
        if ( querySize < 600){
            sqlQuery[querySize - 1] = '\0';
        }
        if ( strcmp(sqlQuery, "quit") ){
            sqlQueryF(dbPath, sqlQuery, strlen(sqlQuery));
        }
    } while ( strcmp(sqlQuery, "quit") );

}

void sqlQueryF(char * dbPath, char * sqlQuery, int querySize){
    char * pointerSave;
    char table[255];
    table[0] = '\0';


    printf("%s\n", sqlQuery);
    pointerSave = strstr(sqlQuery, "INSERT INTO ");
    printf("%s\n", pointerSave);
    if (pointerSave == sqlQuery){
        pointerSave += 12;
        sqlQuery = pointerSave;
        pointerSave = strchr(sqlQuery, ' ');
        printf("%s\n", sqlQuery);
        if ( pointerSave != NULL){
            strncpy(table, sqlQuery, pointerSave - sqlQuery);
            table[pointerSave - sqlQuery] = '\0';
            printf("result : \n");
            printf("|%s|", table);

        }
    }
}

int tableExist(char * dbName){

}
