#include <stdio.h>
#include <stdlib.h>

#define NAME "image.ppm"
#define WIDTH 1920
#define HEIGHT 1080
#define MAX_COLOR 255


void paintFlag(FILE *ptr);
void printHeader(FILE *ptr);
void grayScale();

int main(){
    FILE *ptr = fopen(NAME,"w");
    paintFlag(ptr);
    grayScale();
    return 0;
}
void paintFlag(FILE *ptr){
    int color[3] = {255,0,0};
    printHeader(ptr);
    for(int i = 0; i < WIDTH; i ++){
        for(int j = 0; j < WIDTH; j++){
            if(i > 360 && i < 720){
                color[1] = 255;
            }else{
                color[1] = 0;
            }
            fprintf(ptr,"%d %d %d    ",color[0],color[1],color[2]);
        }

        fprintf(ptr,"\n");
    }
    return;
}
void printHeader(FILE *ptr){
    char header[3] = "P3";
    fprintf(ptr,"%s\n",header);
    fprintf(ptr,"%d %d %d\n",WIDTH,HEIGHT,MAX_COLOR);
    return; 
}
void grayScale(){
    FILE *ptr = fopen(NAME,"r");
    FILE *ptr_grayscale = fopen("grayscale_image.ppm","w");
    char header[3];
    fscanf(ptr,"%s\n",header);
    int sizes[3];
    int pixel[3];
    printHeader(ptr_grayscale);
    fscanf(ptr,"%d %d %d\n",&sizes[0],&sizes[1],&sizes[2]);
    for(int i = 0; i < WIDTH; i ++){
        for(int j = 0; j < WIDTH; j++){
            fscanf(ptr,"%d %d %d    ",&pixel[0],&pixel[1],&pixel[2]);
            int gray =(0.299 * pixel[0]) + (0.587 * pixel[1]) + (0.114 * pixel[2]);
            fprintf(ptr_grayscale,"%d %d %d   ",gray,gray,gray);
        }
        fprintf(ptr_grayscale,"\n");
    }

}
