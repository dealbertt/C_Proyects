#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/ascii.h"
#include "header/grayscale.h"
#include "header/resize.h"
#include "header/utils.h"
#include "header/resize.h"
#include "header/help.h"
#include "header/window.h"

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

    printf("-------------\n"); printf("Welcome to an Image Processor CLI\n");
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
        applyAscii(argv[2]);

    }else if(strcmp("-resize",argv[1]) == 0){

        //Creates and alocates a PPMImage object for the already exising image
        PPMImage *old_image = malloc(sizeof(PPMImage));
        old_image = readFile(argv[2]);
        //It reads the image and assigns the pixel to the old_image PPMImage object
        //This parses from char * to int, in order to properly capture the new width and height
        int w = atoi(argv[3]);
        int h = atoi(argv[4]);
        
        //We now create the new PPMImage object
        //It could edit the already existing image, but wanted to create a new to keep everything more clear
        PPMImage *new_image = malloc(sizeof(PPMImage));
        new_image = resize(old_image, w, h);
        //After resizing, save the file and free the alocated memory
        writeFile(new_image,"resized.ppm");
        displayImage(new_image);
        freeImage(old_image);
        freeImage(new_image);
      
    }else if(strcmp("-help",argv[1]) == 0){
        getHelp();
    }else if(strcmp("-view",argv[1]) == 0){

        PPMImage *image = malloc(sizeof(PPMImage));
        image = readFile(argv[2]);
        displayImage(image); 

    }else{

        commandNotFound(argv[1]);
    }
    return 0;
}
