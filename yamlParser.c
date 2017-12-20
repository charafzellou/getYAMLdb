#include "yml_parser.h"

void YAML_Parser() {
    FILE* file = fopen("DataBases\db1\users.yaml");
    char* stream = malloc(sizeof(char)*2048);
    short pointeur = ftell(file);

    fseek(file, cursorStart, SEEK_SET);

    // Look if file exists
    if(file == NULL)
    {
        fprintf(stderr,"\nERROR, \ncannot open the weather file");
        return -1;
    }

    // Initiate all the cases in the table
    char counter[2] = "",
        number[7] = "",
        average[5] = "",
        humidity[3] = "";

    // Set the cursor to beginning
    fseek(file, 0, SEEK_SET);

    // read line by line
    // JUMP jusqu'au '\0'
    while(actual_char != '\0'{
        actual_char = fgetc(file);
        if(actual_char == ','){
            jump++;
        }
    }
    jump = 0;
    while(jump < 2){
        actual_char = fgetc(file);
         if(actual_char == ':'){
            jump++;
        }
    }
    int i = 0;
    actual_char = fgetc(file);
    while(actual_char != ',')
    {
        databasename[i] = actual_char;
        actual_char = fgetc(file);
        i++;
    }

    fclose(file);
}
