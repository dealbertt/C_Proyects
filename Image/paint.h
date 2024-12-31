#ifndef PAINT_H
#define PAINT_H
#include <stdio.h>
void paintFlag(int width,int heigth, int max_color);

void printHeader(FILE *ptr,int width,int heigth,int max_color);

int paintMenu();

char *getFileName();


#endif 
