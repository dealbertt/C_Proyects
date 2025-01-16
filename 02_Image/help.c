#include <stdio.h>
#include "header/help.h"

void getHelp(){
    printf("\nList of all the commands:\n");
    printf(" -Apply grayscale to an image:\n");
    printf("     -grayscale [FILE NAME]\n\n");
    printf(" -Transform an image into ascii art:\n");
    printf("     -ascii [FILE NAME]\n\n");
    printf(" -Resize an image to a desire width and height:\n");
    printf("     -resize [FILE NAME] [NEW WIDTH] [NEW HEIGHT]\n\n");
    return;
}

void commandNotFound(char *s){
    printf("%s is not a command\n",s);
    getHelp();
    return;
}
