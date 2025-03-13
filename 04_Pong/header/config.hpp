#ifndef CONFIG_H
#define CONFIG_G

#include <iostream>
#include <string.h>
typedef struct Config{
    short ballTimer;
    short padTimer;
    int windowWidth;
    int windowHeigth;
}Config;


Config readConfiguration( const char *path);
#endif
