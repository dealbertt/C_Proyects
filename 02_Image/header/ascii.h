#ifndef ASCII_H
#define ASCII_H
#include <stdio.h>
int getPixelBrigtness(int r,int g,int b);

char method_of_conversion(int greyscale);
void applyAscii(char *fileName); //i can get the size and max_color by scanning the header

#endif 
