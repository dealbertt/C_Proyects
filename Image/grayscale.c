#include "header/grayscale.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "header/utils.h"

int grayArgs(char *fileName){
   if(isFileAvailable(fileName)== 0){
       PPMImage *image = readFile(fileName);
       grayScale(fileName,image);
       freeImage(image);
       
   } 
   return 0;
}



void grayScale(char *fileName,PPMImage *image){ //i can get the size and max_color by scanning the header
                                                
    unsigned char r,g,b;
    for(int i = 0; i < image->height; i++){
        for(int j = 0; j < image->width; j++){
            int index = (j * image->width + i) * 3;

            r = image->pixels[i][j];
            g = image->pixels[i][j + 1];
            b = image->pixels[i][j + 2];
            int gray =(0.299 * r) + (0.587 * g) + (0.114 * b);
            image->pixels[i][j] = gray;
            image->pixels[i][j + 1] = gray;
            image->pixels[i][j + 2] = gray;

        }
    } 

    green();
    printf("Gray Scale applied succesfully to image %s\n",fileName);
    sleep(1);
    white();
    writeFile(image, "grayscale_image.ppm");
    system("feh grayscale_image.ppm");
    return;
}




