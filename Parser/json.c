#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "field.h"
#include "packet.h"
#include "json.h"
#define MAX_STRINGS 5

char *toJson(packet_t *pack,fields_t *fields){
    char *content = NULL;
    if (pack == NULL){
        return NULL;
    }else{
        char *keys[MAX_STRINGS];
        char *content = malloc(sizeof(packet_t));
        toArray(keys,Key(fields->f1),0);   
        toArray(keys,Key(fields->f2),1);   
        toArray(keys,Key(fields->f3),2);   
        strcpy(content,"{\n");
        content = strcat(content,Key(fields->f1));
        content = strcat(content,Value(pack->id));
        content = strcat(content,Key(fields->f2));
        content = strcat(content,Value(pack->firstName)); 
        content = strcat(content,Key(fields->f3));
        content = strcat(content,Value(pack->lastName)); 
        content = strcat(content,"}");
        printf("content in Json Format:\n%s\n",content);
    }
    return content;
}
void toArray(char *arr[],char *line,int index){
    if(index >= 0 && index < MAX_STRINGS){
        arr[index] = strdup(line);
        if(arr[index] == NULL){
            printf("Memory allocation failed for string at index %d\n",index);
        }
    }else{
        printf("INDEX OUT OF BOUNDS\n");
    }
}

char *fieldToJson(char *field){
    char *aux = malloc(sizeof field);
    return field; 
}
char *Value(char *line){
    char *aux = malloc(sizeof line);
    strcpy(aux,"\"");
    aux = strcat(aux,line);    
    line = strcat(aux,"\",\n");
    return line;
}
char *Key(char *line){
    char *aux = malloc(sizeof line);
    strcpy(aux,"\t\"");
    aux = strcat(aux,line);
    line = strcat(aux,"\":");
    return line;
}
