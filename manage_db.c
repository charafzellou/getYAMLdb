#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "create_db.h"
#include "manage_db.h"
#include "delete_db.h"
#define FILE_NAME "text.yaml"

void create_db();
/*
void remove_dir(char *path) {
    //Check if file is deleted

    struct dirent *entry = NULL;
    DIR *dir = NULL;
    dir = opendir("DataBases\\db_del");

    printf("Choose the Database to delete : \n");

    while(entry = readdir(dir))
    {
        DIR *sub_dir = NULL;
        FILE *file = NULL;
        char abs_path[100] = "C:\\Users\\ritch\\Desktop\\test_remove\\DataBases\\db_del";
        if(*(entry->d_name) != '.')
        {
            sprintf(abs_path, "%s%s", path, entry->d_name);
            if(sub_dir = opendir(abs_path))
            {
                closedir(sub_dir);
                remove_dir(abs_path);
            }
            else
            {
                if(file = fopen(abs_path, "r"))
                {
                    fclose(file);
                    remove(abs_path);
                }
            }
        }
    }

   remove(path);
}

int delete_db(){
   int del;
   FILE *fp;
   char filename[] = "file.txt";

   //Check if the file already exist
   fp = fopen(filename, "r+");

   fprintf(fp, "%s", "Blabla");
   fclose(fp);

   del = remove(filename);

   if(del == 0) {
      printf("File deleted successfully\n");
   } else {
      printf("Error: unable to delete the file\n");
   }

   return(0);
}

int menu()
{
    int choice;

    printf("*** Menu ***\n");
    printf("Press 1 to : CREATE A DATABASE\n");
    printf("Press 2 to : USE AN EXISTANT DATABASE\n");
    //To add or destroy a table to add inside the function Use existant database
    printf("Press 3 to : DELETE A DATABASE\n");
    scanf("%d",choice);

    if(choice = 1){
       create_db();
    }
    if(choice = 2){
        manage_db();
    }
    if(choice = 3){
        delete_db();
    }


	//printf("Directory will be created by default in repertory\n");
    //char name_db;

    //printf("Name your DATABASE YAML file : (do not forget the .yaml)\n");
    //scanf("%s", &name_db);


    FILE *fp = fopen(FILE_NAME, "w");

    fclose(fp);


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
*/
