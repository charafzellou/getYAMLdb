#include "yamlParser.h"

int YAML_Parser() {
    //  Initiate all the vars in the table
    FILE* file = fopen("DataBases/db1/users.yaml", "r+b");
    char* stream = malloc(sizeof(char)*2048);
    char actual_char;
    short counterU = 0, counterP = 0;

    //  Look if file exists
    if(file == NULL)
    {
        fprintf(stderr,"\nERROR, cannot open the weather file");
        return -1;
    }

    //  Storing COUNTER - how many records are in the table
    fseek(file, 9, SEEK_SET);
    fgets(stream, 2048, file);
    counterU = strtol(stream, NULL, 10);
    printf("The selected table contains %d records to show:\n", counterU);

    //  Jump to USER1
    fgets(stream, 2048, file);
    printf("%s", stream);
    if(strcmp(stream, "params:\r\n"))
        printf("ERROR: Params not found in YamlDB");
    else
        while(!strcmp(stream, "content:\r\n") == 0){
            fgets(stream, 2048, file);
            printf("%d", counterP);
            counterP++;
        }

    // Insert all data in the table
    char* allData[counterU][counterP];

    fgets(stream, NULL, file);

    /*
    short seekJump = 6;
    while(seekJump > 0){
        actual_char = fgetc(file);
        if(actual_char == '\n')
            seekJump--;
    }
    seekJump = 5;
    while(seekJump > 0){
        fgets(stream, 2048, file);
        printf("%s", stream);
        seekJump--;
    }
    */

    fclose(file);
    return 0;
}
