#include "sqlQuery.h"

void menu1() {
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

    pointerSave = strstr(sqlQuery, "INSERT INTO ");
    if (pointerSave == sqlQuery){
        pointerSave += 12;
        sqlQuery = pointerSave;
        pointerSave = strchr(sqlQuery, ' ');
        if ( pointerSave != NULL){
            strncpy(table, sqlQuery, pointerSave - sqlQuery);
            table[pointerSave - sqlQuery] = '\0';

            if (tableExist(dbPath, table)){
                sqlQuery = pointerSave;
                pointerSave = strstr(sqlQuery, "VALUES");

                if ( pointerSave == sqlQuery + 1 ){
                    sqlQuery = pointerSave;
                    pointerSave = strchr(sqlQuery, ' ');
                    dataInsertion(dbPath, table, pointerSave);
                }
            } else {
                printf("Cette table n'existe pas /:\n");
            }

        }
    }
}

int tableExist(char * dbPath, char * tableName){
    char tablePath[500] = "DataBases\\";
    FILE* fTable;
    tablePath[11] = '\0';

    strcat(tablePath, dbPath);
    strcat(tablePath, "\\");
    strcat(tablePath, tableName);
    strcat(tablePath, ".yaml");
    fTable = fopen(tablePath, "r");
    if ( fTable != NULL){
        fclose(fTable);
        return EXIT_FAILURE;
    } else {
        return EXIT_SUCCESS;
    }
}

void dataInsertion(char * dbPath, char * dbName, char * values){
    char tablePath[500] = "DataBases\\";
    FILE* fTable;
    tablePath[11] = '\0';
    char * tableYaml;
    int fileSize;
    char tableCounter[10];
    tableCounter[0] = '\0';
    char * pointerSave;
    char * tableYamlSave;
    char * tableYamlStop;
    int putcounter = 0;

    strcat(tablePath, dbPath);
    strcat(tablePath, "\\");
    strcat(tablePath, dbName);
    strcat(tablePath, ".yaml");

    fTable = fopen(tablePath, "r+");

    if ( fTable != NULL ){
        fileSize = fileLen(fTable);
        tableYaml = malloc(sizeof(char) * fileSize);
        if (tableYaml != NULL){
            fseek(fTable, 0, SEEK_SET);
            fread(tableYaml, sizeof(char), fileSize, fTable);
            printf("%s\n", tableYaml);
            strncpy(tableCounter, strchr(tableYaml, ' ') + 1, strchr(tableYaml, '\n') - strchr(tableYaml, ' ') - 1 );
            tableCounter[strchr(tableYaml, '\n') - strchr(tableYaml, ' ') - 1] = '\0';
            tableCounterPlusplus(tableCounter);
            values = strchr(values, '(');
            if ( values != NULL ){
                pointerSave = strchr( values, ')');
                if ( pointerSave != NULL ){
                    fseek(fTable, 0, SEEK_END);
                    fprintf(fTable, "    %s %s: \r\n", dbName, tableCounter);
                    tableYamlSave = strstr( tableYaml, "params:");
                    tableYamlStop = strstr( tableYaml, "content:");
                    if ( tableYamlSave != NULL && tableYamlStop != NULL){

                        do{
                            if ( tableYamlSave > tableYamlStop ) {
                                break;
                            }
                            tableYamlSave = strstr( tableYamlSave, "    ");
                            fputs("    ", fTable);
                            while( tableYamlSave[putcounter] != ':'){
                                fputc(tableYamlSave[putcounter], fTable);
                                putcounter++;
                            }
                            putcounter = 1;
                            fputs(": ", fTable);
                            if ( values != NULL){
                                while ( values[putcounter] != ','){
                                    if ( values[putcounter] == ')'){
                                        values = NULL;
                                        break;
                                    }
                                    fputc(values[putcounter], fTable);
                                    putcounter++;
                                }
                                values = strchr(values, ',');
                            } else {
                                fputs("NULL", fTable);
                            }
                            fputs("\n\r", fTable);
                            putcounter = 0;
                            tableYamlSave++;
                        } while(tableYamlSave < tableYamlStop);
                    } else {
                        printf("error");
                    }
                } else {
                    printf("Error: Expecting ')'");
                }
            } else {
                printf("Error: Expecting '('");
            }

            free(tableYaml);
        }
        fclose(fTable);
    } else {
        printf("une erreur est survenue x(");
    }


}

int fileLen(FILE* pf){
    int counter = 0;
    fseek(pf, 0, SEEK_SET);

    while( !feof(pf) ){
        fgetc(pf);
        counter++;
    }
    return counter;
}

char * tableCounterPlusplus( char * counter){
    int length;

    length = strlen(counter);

    switch(length){
        case 1:
            if ( counter[0] - 48 == 9){
                counter[0] = '1';
                counter[1] = '0';
                counter[2] = '\0';
            } else {
                counter[0]++;
            }
            break;
        case 2:
            if ( counter[1] - 48 == 9){
                if ( counter[0] - 48 == 9){
                    counter[2] = 0;
                    counter[1] = counter[0]++;
                    counter[0] = '1';
                    counter[3] = '\0';
                } else {
                    counter[1] = '0';
                    counter[0]++;
                }
            } else {
                counter[1]++;
            }
            break;
        case 3:
            if ( counter[2] - 48 == 9){
                if ( counter[1] - 48 == 9){
                    if ( counter[0] - 48 == 9 ){
                        counter[4] = '\n';
                        counter[3] = '0';
                        counter[2] = '0';
                        counter[1] = '0';
                        counter[0] = '1';
                    } else {
                        counter[0]++;
                        counter[1] = '0';
                        counter[2] = '0';
                    }
                } else {
                    counter[1]++;
                    counter[2] = '0';
                }
            } else {
                counter[2]++;
            }
            break;
        case 4:
            if ( counter[3] - 48 == 9){
                if ( counter[2] - 48 == 9){
                    if ( counter[1] - 48 == 9 ){
                        if ( counter[0] - 48 == 9){
                            counter[5] = '\n';
                            counter[4] = '0';
                            counter[3] = '0';
                            counter[2] = '0';
                            counter[1] = '0';
                            counter[0] = '1';
                        } else {
                            counter[3] = '0';
                            counter[2] = '0';
                            counter[1] = '0';
                            counter[0]++;
                        }
                    } else {
                        counter[1]++;
                        counter[2] = '0';
                        counter[3] = '0';
                    }
                } else {
                    counter[2]++;
                    counter[3] = '0';
                }
            } else {
                counter[3]++;
            }
            break;
        case 5:
            if ( counter[4] - 48 == 9){
                if ( counter[3] - 48 == 9){
                    if ( counter[2] - 48 == 9 ){
                        if ( counter[1] - 48 == 9){
                            if ( counter[0] - 48 == 9){
                                counter[6] = '\n';
                                counter[5] = '0';
                                counter[4] = '0';
                                counter[3] = '0';
                                counter[2] = '0';
                                counter[1] = '0';
                                counter[0] = '1';
                            } else {
                                counter[0]++;
                                counter[1] = '0';
                                counter[2] = '0';
                                counter[3] = '0';
                                counter[4] = '0';
                            }
                        } else {
                            counter[1]++;
                            counter[2] = '0';
                            counter[3] = '0';
                            counter[4] = '0';
                        }
                    } else {
                        counter[2]++;
                        counter[3] = '0';
                        counter[4] = '0';
                    }
                } else {
                    counter[3]++;
                    counter[4] = '0';
                }
            } else {
                counter[4]++;
            }
            break;
    }

    return counter;
}
