#include "yamlParser.h"

int YAML_Parser() {
    FILE* file = fopen("DataBases/db1/users.yaml", "rb+");
    char* stream = malloc(sizeof(char)*2048);
    short pointeur = ftell(file);
    char actual_char;

    // Look if file exists
    if(file == NULL)
    {
        fprintf(stderr,"\nERROR, \ncannot open the weather file");
        return -1;
    }

    // Initiate all the vars in the table
    int counter;
    float number;
    char average;
    char* humidity;
    char c_counter[256], c_number[256], c_average[256], c_humidity[256];

    // Set the cursor at beginning
    fseek(file, 0, SEEK_SET);

    // read line by line
    fseek(file, 9, SEEK_SET);
    short i = 0;
    while(actual_char != '\n'){
        actual_char = fgetc(file);
        printf("%c", actual_char);
        c_counter[i] = actual_char;
        i++;
    }

    fclose(file);
    return 0;
}
