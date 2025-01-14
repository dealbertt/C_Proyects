#ifndef GRAYSCALE_H
#define GRAYSCALE_H
#include <stdio.h>
#include "utils.h"

void grayScale(char *fileName,PPMImage image); //i can get the size and max_color by scanning the header
void grayMenu();
void listImages();
int isFileAvailable(char *fileName);
int grayArgs(char *fileName);
#endif
