/*
** Filename : main.c
**
** Made by :
**
** Description : this is code purpose is to manage a database whit Yaml files
*/

#include <stdio.h>
#include "sqlQuery.h"
#include "yamlParser.h"

int main() {
    char name[255];
    char choiceMenu1;

    do{
        printf("----   MENU   ----\n");
        printf("a.   partie 1\n");
        printf("b.   partie 2\n");
        printf("c.   partie 3\n");
        printf("q.   quitter\n");
        scanf("%c", &choiceMenu1);
        fflush(stdin);
        system("cls");
        switch(choiceMenu1){
            case 'a':

                break;
            case 'b':
                menu1();
                break;
            case 'c':
                YAML_Parser();
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
    //  Create Database
    //  Create Table
    //  Create Record

    //  Read Record
    //  Modify Record
    //  Delete Record

    //  Modify Table
    //  Create Record
    //  Read Record
    //  Delete Record

    //  Delete Table
    //  Delete Database
    return 0;
}
