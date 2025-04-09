#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <string.h>

typedef struct Config{
    int numberElements;
    int windowWidth;
    int windowHeigth;
    int fps;
}Config;

Config *readConfiguration(const char *);

#endif


