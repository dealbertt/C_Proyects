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


MAP_t *loadLevel();
List  *createList();
int levelList(MAP_t **map);
#endif
