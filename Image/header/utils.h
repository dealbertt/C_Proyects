#ifndef UTILS_C
#define UTILS_C

#define MAX_SIZE 50 //max size for the name of the file
#define clear() printf("\033[H\033[J")
#define red() printf("\033[31m")
#define blue() printf("\033[34m")
#define green() printf("\033[32m")
#define yellow() printf("\033[33m")
#define white() printf("\033[0m")
#define WIDTH 1920
#define HEIGHT 1080
#define MAX_COLOR 255
#define NAME "image.ppm"

#include <stdio.h>

typedef struct{
    int width;
    int height;
    int max_color;
    unsigned char *pixels;
}PPMImage;

void listImages();

int isFileAvailable(char *fileName);

int isNameTaken(char *fileName);
char *getFileName();
void printHeader(FILE *ptr,int width,int height,int max_color);
PPMImage *readFile(char *fileName);
int writeFile(PPMImage *old_image,char *newFile);
#endif
