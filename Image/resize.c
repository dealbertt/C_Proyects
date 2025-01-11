#include "header/resize.h"
#include "header/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


PPMImage *resize(PPMImage *old_image, int new_width, int new_heigth){
    printf("Inside the function\n");
    unsigned char *pixels = (unsigned char *) malloc(3 * new_width * new_heigth);
    for(int i = 0; i < new_width; i++){
        for(int j = 0; j < new_heigth;j++){

            printf("Inside the loop\n");
            int orig_x = (int)floor(i * ((float)old_image->width / new_width));
            int orig_y = (int) floor(j * ((float)old_image->height / new_heigth));

            int orig_index = (orig_x * old_image->width + orig_y) * 3;
            unsigned char r_orig = old_image->pixels[orig_index];
            unsigned char g_orig = old_image->pixels[orig_index + 1];
            unsigned char b_orig = old_image->pixels[orig_index + 2];
            int resized_index = (j * new_width + i) * 3;
            
            pixels[resized_index] = r_orig;
            pixels[resized_index + 1] = g_orig;
            pixels[resized_index + 2] = b_orig;

        }
    } 

    printf("After the loop\n");
    PPMImage *new_image = (PPMImage *) malloc(sizeof(PPMImage));
    new_image->width = new_width;
    new_image->height= new_heigth;
    new_image->max_color = old_image->max_color;
    new_image->pixels = pixels;
    return new_image;
}


