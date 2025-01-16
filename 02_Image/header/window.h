#ifndef WINDOW_H
#define WINDOW_H

#include "utils.h"
#include <SDL2/SDL.h>
void displayImage(PPMImage *image);
unsigned int rgbToHex(unsigned char r, unsigned char g, unsigned char b);
void displayAscii(char *fileName);
#endif // !WINDOW_H
