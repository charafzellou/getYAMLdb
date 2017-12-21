#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define FILE_NAME "text.yaml"

int delete_db(){

    int del;
        //FILE *fp;

    FILE *fp = fopen(FILE_NAME, "w");
    fclose(fp);

    del = remove(FILE_NAME);

    if(del == 0){
        printf("File correctly deleted\n");
    } else {

        printf("Error : Cannot delete the file\n");
    }
    return 0;
}
