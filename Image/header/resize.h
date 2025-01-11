#ifndef RESIZE_H
#define RESIZE_H
#include "utils.h"
#include <math.h>
PPMImage *resize(PPMImage *old_image,int width,int height);
int checkSizes(int w,int h);

#endif 
