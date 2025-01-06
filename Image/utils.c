#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
void listImages(){

    struct dirent *de;
    DIR *dir = opendir(".");

    if(dir == NULL){

        printf("Could open the directory\n");

    }
    while ((de = readdir(dir)) != NULL){

        char *listedFile = de->d_name;
        if(strstr(listedFile,".ppm")!= NULL){

            printf("%s\n",listedFile);

        }

    }
}
int isFileAvailable(char *fileName){

    struct dirent *de;
    DIR *dir = opendir(".");

    if(dir == NULL){

        printf("Could open the directory\n");

    }

    while ((de = readdir(dir)) != NULL){

        char *listedFile = de->d_name;
        if(strcmp(listedFile,fileName) == 0){

            printf("File is available\n");

            return 0;
        }
    }
    red();
    printf("No file with the name available\n");
    white();
    return 1;
}

int isNameTaken(char *fileName){

    struct dirent *de;
    DIR *dir = opendir(".");

    if(dir == NULL){
        
        printf("Could open the directory\n");

    }
    while ((de = readdir(dir)) != NULL){

        char *listedFile = de->d_name;
        if(strcmp(listedFile,fileName) == 0){

            red();
            printf("Another file with the same name already exists\n Please choose a different name\n");
            white();

            return 1;

        }
    }
    return 0;
}
void printHeader(FILE *ptr,int width,int height,int max_color){
    char header[3] = "P6";
    fprintf(ptr,"%s\n",header);
    fprintf(ptr,"%d %d %d\n",width,height,max_color);

    return; 

}
char *getFileName(){

    char *name = (char *) malloc(MAX_SIZE * sizeof(char));
    printf("Please introduce the name of the file(without .ppm at the end):");
    scanf("%s",name);

    char file_extension[4] = ".ppm";
    char *p = strstr(name,file_extension);

    if(!p){

        strcat(name,file_extension);
        printf("File name:%s",name);

    }
    if(isNameTaken(name) == 1){

        return NULL;

    }
    return name;
}
