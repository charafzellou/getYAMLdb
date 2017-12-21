#include "yamlParser.h"

int YAML_Parser() {
    //  Initiate all the vars in the table
    FILE* file = fopen("DataBases/db1/users.yaml", "rb+");
    char* stream = malloc(sizeof(char)*2048);
    short pointeur = ftell(file);
    char actual_char;

    short counter;
    float number;
    char average;
    char* humidity;
    char c_counter[256], c_number[256], c_average[256], c_humidity[256];

    //  Look if file exists
    if(file == NULL)
    {
        fprintf(stderr,"\nERROR, cannot open the weather file");
        return -1;
    }

    //  Storing COUNTER - how many records are in the table
    fseek(file, 9, SEEK_SET);
    actual_char = fgetc(file);
    if(actual_char != '\n')
        counter = (int)actual_char;
    printf("The selected table contains %c records to show:\n", counter);

    //  Saut jusqu'au USER1
    short seekJump = 7;
    while(seekJump > 0){
        actual_char = fgetc(file);
        if(actual_char == '\n'){
            seekJump--;
        }
    }

    seekJump = 5;
    while(seekJump > 0){
        fgets(stream, 128, file);
        printf("%s", stream);
        seekJump--;
    }

    fclose(file);
    return 0;
}
