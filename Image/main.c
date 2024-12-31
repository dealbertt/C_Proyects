#include <stdio.h>
#include <stdlib.h>
#include "paint.h"
#define NAME "image.ppm"
#define WIDTH 1920
#define HEIGHT 1080
#define MAX_COLOR 255
#define clear() printf("\033[H\033[J")

//Read all the files in the folder
//input the user to introduce the name for the file they want to create


void grayScale();
int Menu();

int main(){
    int option = 0;
    while(option != 4){
        option = Menu();
        switch (option) {
            case 1: 
                clear();
                //Create a new image
                int option = 0;
                while(option != 3){
                    option = paintMenu();
                    switch (option) {
                    case 1:
                        paintFlag(WIDTH, HEIGHT, MAX_COLOR);
                        break;
                    }
                } 
                break;

            case 2:
                clear();
                //Apply Gray Scale
                grayScale();
                break;

            case 3:
                clear();
                //Invert Colors
                break;
        }
    }
    return 0;
}
int Menu(){
    int option = 4;
    clear();
    printf("-------------\n");
    printf("Welcome to an Image Processor CLI\n");
    printf("1. Create new image (Spanish flag by default)\n");
    printf("2. Apply Gray Scale to an existing image\n");
    printf("3. Invert Colors\n");
    printf("4. Exit\n");
    printf("-------------\n");
    do{
        printf("Please introduce a number between 1 and 4\n");
        scanf("%d",&option);

    }while(option > 4 || option < 1);

    return option;
}

void grayScale(){
    FILE *ptr = fopen(NAME,"r");
    FILE *ptr_grayscale = fopen("grayscale_image.ppm","w");
    char header[3];
    fscanf(ptr,"%s\n",header);
    int sizes[3];
    int pixel[3];
    printHeader(ptr_grayscale,WIDTH,HEIGHT,MAX_COLOR);
    fscanf(ptr,"%d %d %d\n",&sizes[0],&sizes[1],&sizes[2]);
    for(int i = 0; i < WIDTH; i ++){
        for(int j = 0; j < WIDTH; j++){
            fscanf(ptr,"%d %d %d    ",&pixel[0],&pixel[1],&pixel[2]);
            int gray =(0.299 * pixel[0]) + (0.587 * pixel[1]) + (0.114 * pixel[2]);
            fprintf(ptr_grayscale,"%d %d %d   ",gray,gray,gray);
        }
        fprintf(ptr_grayscale,"\n");
    }
    return;
}
