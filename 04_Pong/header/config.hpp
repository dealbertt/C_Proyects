#ifndef CONFIG_H
#define CONFIG_G

#include <iostream>
#include <string.h>
typedef struct Config{
    float ballSpeed;
    float padSpeed;
    int windowWidth;
    int windowHeigth;
    int fps;
}Config;


Config readConfiguration( const char *path);
#endif
