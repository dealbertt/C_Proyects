#include <stdio.h>
#include <stdlib.h>
#include "header/paint.h"
#include "header/grayscale.h"
#include "header/utils.h"
#include "header/ascii.h"


//DEFINE SECTION 
//this includes the standar image size and the max rgb color (for the header section)
//Read all the files in the folder
//input the user to introduce the name for the file they want to create
int Menu();

int main(){

    int color[3] = {255,255,255};
    printf("brightness: %d\n",getPixelBrigtness(color[0],color[1],color[2]));
    int option = 0;
    while(option != 4){

        option = Menu();

        switch (option) {
            case 1: 
                clear();
                //Create an image
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
                //Apply Gray Scale
                clear();
                grayMenu();
                break;

            case 3:
                clear();
                //Invert Colors
                applyAscii();
                break;
        }
    }
    return 0;
}
int Menu(){

    int option = 4;
    clear();

    printf("-------------\n");
    red();
    printf("Welcome to an Image Processor CLI\n");
    green();
    printf("1. Create new image (Spanish flag by default)\n");
    blue();
    printf("2. Apply Gray Scale to an existing image\n");
    yellow();
    printf("3. Transform an image into ASCII\n");
    white(); 
    printf("4. Exit\n");
    printf("-------------\n");

    do{
        printf(" Please introduce a number between 1 and 4\n");
        scanf("%d",&option);

    }while(option > 4 || option < 1);

    return option;
}


