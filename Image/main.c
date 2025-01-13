#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/grayscale.h"
#include "header/resize.h"
#include "header/utils.h"
#include "header/resize.h"
#include "header/help.h"








//DEFINE SECTION 
//this includes the standar image size and the max rgb color (for the header section)
//Read all the files in the folder
//input the user to introduce the name for the file they want to create
int checkArgument(char **argv);
int main(int argc, char **argv){
    if(argc == 1){
        printf("Please provide an argument\n");
        return 1;
    }
    checkArgument(argv);
    return 0;

}
int Menu(){

    int option = 4;
    clear();

    printf("-------------\n");
    printf("Welcome to an Image Processor CLI\n");
    printf("1. Create new image (Spanish flag by default)\n");
    printf("2. Apply Gray Scale to an existing image\n");
    printf("3. Transform an image into ASCII\n");
    printf("4. Exit\n");
    printf("-------------\n");

    do{
        printf(" Please introduce a number between 1 and 4\n");
        scanf("%d",&option);

    }while(option > 4 || option < 1);

    return option;
}

int checkArgument(char **argv){
    if(strcmp("-grayscale",argv[1]) == 0){

        grayArgs(argv[2]);

    }else if(strcmp("-ascii",argv[1]) == 0){

    }else if(strcmp("-resize",argv[1]) == 0){
        PPMImage *old_image = readFile(argv[2]);
        int w = atoi(argv[3]);
        int h = atoi(argv[4]);
        PPMImage *new_image = resize(old_image, w, h);
        writeFile(new_image,"resized.ppm");
        free(old_image);
        free(new_image->pixels);
        free(new_image);
        
    }else if(strcmp("-help",argv[1]) == 0){
        getHelp();
            
    }else{
        commandNotFound(argv[1]);
    }
    return 0;
}
