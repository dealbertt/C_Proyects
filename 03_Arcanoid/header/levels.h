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
#define BLUE 0xFF0000FF
#define RED 0xFFFF0000
#define PURPLE 0xFFFF00FF
#define GREEN 0xFF00FF000
#define TURQUOISE 0xFF40E0D0
#define YELLOW 0xFFFFFF00
#define WHITE 0xffffffff


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
MAP_t *pop(List *list);
int resetObjects(PAD *pad, BALL *ball, List *list, SDL_Surface *surface, SDL_Window *window);
#endif
