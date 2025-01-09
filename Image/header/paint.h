#ifndef PAINT_H
#define PAINT_H
#include <stdio.h>

void paintFlag();

void printHeader(FILE *ptr,int width,int heigth,int max_color);

int paintMenu();

char *getFileName();

int isNameTaken(char *fileName);
int paintArg(char *preset);

#endif 
