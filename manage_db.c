#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "create_db.h"
#include "manage_db.h"
#include "delete_db.h"
#define FILE_NAME "text.yaml"

void create_db();

int main()
{
    int choice;

    /*
    printf("*** Menu ***\n");
    printf("Press 1 to : CREATE A DATABASE\n");
    printf("Press 2 to : USE AN EXISTANT DATABASE\n");
    //To add or destroy a table to add inside the function Use existant database
    printf("Press 3 to : DELETE A DATABASE\n");
    scanf("%d",choice);
    */
    /*
    if(choice = 1){
       create_db();
    }
    if(choice = 2){
        manage_db();
    }
    if(choice = 3){
        delete_db();
    }
    */

	//printf("Directory will be created by default in repertory\n");
    //char name_db;

    //printf("Name your DATABASE YAML file : (do not forget the .yaml)\n");
    //scanf("%s", &name_db);

    /*
    FILE *fp = fopen(FILE_NAME, "w");

    fclose(fp);
    */

    int del;

    FILE *fp = fopen(FILE_NAME, "w");
    fclose(fp);

    del = remove(fp);

    if(del == 0){
        printf("File correctly deleted\n");
    } else {
        printf("Error : Cannot delete the file\n");
    }
    return 0;
}
