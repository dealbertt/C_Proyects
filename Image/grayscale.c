#include "header/grayscale.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "header/utils.h"



void grayMenu(){

    clear();

    printf("List of all the available image:\n");
    listImages();
    printf("Type the file you want to grayscale (a new file will be created):\n");

    char *chosedFile = (char *) malloc(MAX_SIZE * sizeof(char));
    scanf("%s",chosedFile);

    if(isFileAvailable(chosedFile) == 0){

        //apply grayscale
        grayScale(chosedFile);

    }else{
        return;

    }
}

void grayScale(char *fileName){ //i can get the size and max_color by scanning the header
                                //
    FILE *ptr = fopen(fileName,"r");
    FILE *ptr_grayscale = fopen("grayscale_image.ppm","w");

    char header[3];
    int sizes[3];

    fscanf(ptr,"%s\n",header);
    fscanf(ptr,"%d %d %d",&sizes[0],&sizes[1],&sizes[2]);

    int pixel[3];
    printHeader(ptr_grayscale,sizes[0],sizes[1],sizes[2]);

    for(int i = 0; i < sizes[0]; i ++){

        for(int j = 0; j < sizes[1]; j++){

            fscanf(ptr,"%d %d %d    ",&pixel[0],&pixel[1],&pixel[2]);
            int gray =(0.299 * pixel[0]) + (0.587 * pixel[1]) + (0.114 * pixel[2]);
            fprintf(ptr_grayscale,"%d %d %d   ",gray,gray,gray);

        }

        fprintf(ptr_grayscale,"\n");

    }

    green();
    printf("Gray Scale applied succesfully to image %s\n",fileName);
    sleep(1);
    white();
    fclose(ptr);
    fclose(ptr_grayscale);
    free(fileName);
}




