#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct{
    int width;
    int height;
    int max_color;
    unsigned char *pixels;
}PPMImage;

