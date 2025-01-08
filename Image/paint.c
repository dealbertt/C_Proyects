#include "header/paint.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "header/utils.h"
#include "header/ascii.h"

#define FILE_NAME "spanish.ppm"

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
int paintArg(char *preset){
    if(strcmp("-spanish",preset) == 0){
        paintFlag();
    }else{
        printf("Argument for painting not received\n");
    }
    return 0;
}

void paintFlag(){

    int color[3] = {255,0,0};
    FILE *ptr_new = fopen(FILE_NAME,"w");
    printHeader(ptr_new,WIDTH,HEIGHT,MAX_COLOR);

    for(int i = 0; i < WIDTH; i ++){

        for(int j = 0; j < HEIGHT; j++){

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
    printf("File with name %s has been created succesfully\n",FILE_NAME);
    white();
    fclose(ptr_new);
    return;
}


