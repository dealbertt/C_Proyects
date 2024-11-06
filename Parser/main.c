#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packet.h"
#include "field.h"
#define NAME "file.csv"
#define LENGHT 50
#define limit ","
#define MAX_FIELDS 3


char *ReadLine(FILE *ptr);
FILE *OpenFile();
packet_t *ProcessLine(char *line);

int main(){
    FILE *ptr = OpenFile();
    fields_t *field_test = detectFields(ptr,MAX_FIELDS);
    //array_t *test = detectFields_test(ptr,MAX_FIELDS);
    stack_t *stack =createStack();
    char *content;
    packet_t *packet = NULL;
    while((content = ReadLine(ptr))!= NULL){
        packet = ProcessLine(content);
        if(packet !=NULL ){
            push(packet,stack);
        }else{
            printf("Error:Failed to process line\n");
        }
        //free(content);
    }
    PrintStack(stack,field_test);
    fclose(ptr);
    freeStack(stack);
    return 0;
}

FILE *OpenFile(){
    FILE *ptr = fopen(NAME,"r");
    if(ptr == NULL){
        printf("Error opening the file\n");
        return NULL;
    }else{
        return ptr;
    }
}

packet_t *ProcessLine(char *line){
    packet_t *pack;
    pack = malloc(sizeof(packet_t));
    if(pack == NULL){
        perror("Error alocating memory for the packet\n");
        return NULL;
    }
    int i = 0;
    char *token;
    token = strtok(line,limit);
    while(token!= NULL){
        if(i == 0){
            strcpy(pack->id,token);
        }else if(i == 1){
            strcpy(pack->firstName,token);
        }else if(i == 2){
            strcpy(pack->lastName,token);
        }
        i++;
        token = strtok(NULL,limit);//NULL in this case is to continue where it left off in the last token
    }
    return pack;

}


