#include "paint.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define clear() printf("\033[H\033[J")
#define MAX_SIZE 50 //max size for the name of the file
int paintMenu(){

    int option = 3;

    printf("------------\n");
    printf("1. Spanish flag\n");
    printf("2. Work in progress\n");
    printf("3. Go back to main menu\n");
    printf("Choose an option\n");

    do{

        scanf("%d",&option);

    }while(option < 1 || option > 3);

    return option;
}

void paintFlag(int width,int heigth,int max_color){

    int color[3] = {255,0,0};
    char *name;

    if((name = getFileName()) == NULL){

        return;

    }
    FILE *ptr_new = fopen(name,"w");
    printHeader(ptr_new,width,heigth,max_color);

    for(int i = 0; i < width; i ++){

        for(int j = 0; j < heigth; j++){

            if(i > 640&& i < 1280){

                color[1] = 255;

            }else{

                color[1] = 0;

            }

            fprintf(ptr_new,"%d %d %d    ",color[0],color[1],color[2]);
        }

        fprintf(ptr_new,"\n");
    }

    printf("File with name %s has been created succesfully\n",name);
    return;
}

void printHeader(FILE *ptr,int width,int height,int max_color){

    char header[3] = "P3";
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

int isNameTaken(char *fileName){

    struct dirent *de;
    DIR *dir = opendir(".");

    if(dir == NULL){
        
        printf("Could open the directory\n");

    }
    while ((de = readdir(dir)) != NULL){

        char *listedFile = de->d_name;
        if(strcmp(listedFile,fileName) == 0){

            printf("Another file with the same name already exists\n Please choose a different name\n");

            return 1;

        }
    }
    return 0;
}
