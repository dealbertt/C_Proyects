#include "header/paint.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "header/utils.h"
#include "header/ascii.h"

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

                if(i > WIDTH / 3&& i < (WIDTH - WIDTH/3)){

                color[1] = 255;

            }else{

                color[1] = 0;

            }

            fprintf(ptr_new,"%d %d %d    ",color[0],color[1],color[2]);
        }

        fprintf(ptr_new,"\n");
    }

    green();
    printf("File with name %s has been created succesfully\n",name);
    white();
    fclose(ptr_new);
    free(name);
    return;
}


