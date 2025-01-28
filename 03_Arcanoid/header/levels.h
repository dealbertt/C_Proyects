#ifndef LEVELS_H
#define LEVELS_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int loadLevel(MAP_t *level);
int levelList(MAP_t **map);
void addToList(List *list,char levelName[15]);
#endif
