#ifndef LEVELS_H
#define LEVELS_H
#include <stdbool.h>

typedef struct MAP{
    char name[15];
    int bricks;
    int destructibleBricks;
    bool completed;
    struct MAP *next;

}MAP_t;

typedef struct{
    MAP_t *top;
    MAP_t *tail;

}list_t;


MAP_t *loadLevel();
list_t*createList();
void freeStack(list_t *list);
void push(MAP_t *map,list_t *list);
MAP_t *pop(list_t *stack);

#endif
