#ifndef LEVELS_H
#define LEVELS_H
#include <SDL2/SDL_surface.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "graphics.h"


#define BLACK 0x00000000
#define WHITE 0xffffffff
#define RED 0xFFFF0000
#define BLUE 0xFF0000FF
#define GREEN 0xFF00FF000

typedef struct MAP{
    char name[15];
    int bricks;
    bool completed;
    struct MAP *next;

}MAP_t;

typedef struct{
    struct MAP *head;
    struct MAP *tail;
    int size;

}List;


List  *createList();
int loadLevel(MAP_t *level,SDL_Surface *surface);
int levelList(MAP_t **map);
void addToList(List *list,char levelName[15]);
uint32_t selectColor(int n);
#endif
