#include "paint.h"
#include <stdio.h>
#include <stdlib.h>
#define clear() printf("\033[H\033[J")
#define MAX_SIZE 50
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
    clear();
    char file_name[15];
    char *name = getFileName();
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
    return name;
}
