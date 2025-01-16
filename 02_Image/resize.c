#include "header/resize.h"
#include "header/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//This uses the nearest neightbor algorithm, which locates the corresping pixels on the image based on the ration between the old values and new values
//
//

PPMImage *resize(PPMImage *old_image, int new_width, int new_heigth){

    PPMImage *new_image = malloc(sizeof(PPMImage));
    allocatImage(new_image,  new_width, new_heigth,  old_image->max_color);

    int widthRatio = old_image->width/ new_width;
    int heigthRatio = old_image->height/ new_heigth;
    for(int i = 0; i < new_heigth; i++){
        for(int j = 0; j < new_width;j++){
            int x =floor(j * widthRatio);
            int y =floor(i * heigthRatio);

            unsigned char r = old_image->pixels[y][x * 3];
            unsigned char g = old_image->pixels[y][x * 3 + 1];
            unsigned char b = old_image->pixels[y][x * 3 + 2];

            new_image->pixels[i][j * 3] = r;
            new_image->pixels[i][j * 3 + 1] = g;
            new_image->pixels[i][j * 3 + 2] = b;

            

        }
    } 

    printf("Image resized sucesfully\n");
    return new_image;
}


