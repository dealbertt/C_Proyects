#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "field.h"

#define LENGTH 50
#define limit ","

array_t *detectFields_test(FILE *ptr,int n){
    array_t *keys = malloc(sizeof(array_t));
    if(keys == NULL){
        printf("Error alocating memory\n");
        return NULL;
    }
    char *line = (char *)malloc(LENGTH * sizeof(char));
    line = ReadLine(ptr);
    char *token;
    token = strtok(line,limit);
    while(token != NULL){
        if(n == 3){
           keys->values[n - 1] = strdup(token); 
        }else if(n == 2){
            keys->values[n - 1] = strdup(token);
        }else if(n == 1){
            keys->values[n - 1] = strdup(token);
        }
        n--;
        token = strtok(NULL,limit);
    }
    printf("f1:%s\nf2:%s\nf3:%s\n",keys->values[0],keys->values[1],keys->values[2]);
    free(keys);
    return keys;
}

fields_t *detectFields(FILE *ptr, int n){
    fields_t *field = malloc(sizeof(fields_t));
    array_t *keys = malloc(sizeof(array_t));
    if(field == NULL){
        printf("Error alocating memory\n");
        return NULL;
    }
    char *line = (char *)malloc(LENGTH * sizeof(char));
    line = ReadLine(ptr);
    char *token;
    token = strtok(line,limit);
    while(token != NULL){
        if(n == 3){
            strcpy(field->f1,token);
            keys->values[n - 1] = strdup(token);
        }else if(n == 2){
            strcpy(field->f2,token);
            keys->values[n - 1] = strdup(token);
        }else if(n == 1){
            strcpy(field->f3,token);
            keys->values[n - 1] = strdup(token);
        }
        n--;
        token = strtok(NULL,limit);
    }
    //printf("f1:%s\nf2:%s\nf3:%s\n",field->f1,field->f2,field->f3);
    free(keys);
    return field;
}

char *ReadLine(FILE *ptr){
    char *line = (char *)malloc(LENGTH * sizeof(char));
    if(fgets(line,LENGTH,ptr) != NULL){
        return line;
    }else{
        free(line);
        return NULL;
    }
    return NULL;
}

