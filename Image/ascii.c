#include "header/ascii.h"
#include <stdio.h>
#include "header/utils.h"
#include <unistd.h>


//How to extract brightness out of rgb: 0.2126*R + 0.7152*G + 0.0722*B

int getPixelBrigtness(int r,int g,int b){
   int bright = (0.2126 * r) + (0.7152*g) + (0.0722 * b);
    return bright;
}
char method_of_conversion(int greyscale){
    if(greyscale >= 230){
        return ' ';
    }else if(greyscale >= 200 ){
        return ',';
    }else if(greyscale >= 180 ){
        return ':';
    }else if(greyscale >= 160 ){
        return '^';
    }else if(greyscale >= 130 ){
        return '-';
    }else if(greyscale >= 100 ){
        return '*';
    }else if(greyscale >= 70 ){
        return '8';
    }else if(greyscale >= 50 ){
        return '=';
    }else {
        return '#';
    }
}
void applyAscii(){ //i can get the size and max_color by scanning the header
                                //
    FILE *ptr = fopen("bclc.ppm","r");
    FILE *ascii_ptr = fopen("ascii.txt","w");

    char header[3];
    int sizes[3];

    fscanf(ptr,"%s\n",header);
    fscanf(ptr,"%d %d %d",&sizes[0],&sizes[1],&sizes[2]);
    int pixel[3];

    int counter = 0;
    clear();
    for(int i = 0; i < sizes[0]; i ++){

        for(int j = 0; j < sizes[1]; j++){

            fscanf(ptr,"%d %d %d    ",&pixel[0],&pixel[1],&pixel[2]);
            int bright = getPixelBrigtness(pixel[0],pixel[1],pixel[2]);
            fprintf(ascii_ptr,"%c",method_of_conversion(bright));
            counter ++;

        }

        fprintf(ascii_ptr,"\n");

    }

    green();
    white();
    printf("Total pixels: %d\n",counter);
    sleep(4);
    fclose(ptr);
    fclose(ascii_ptr);
}
