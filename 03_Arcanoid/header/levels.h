#ifndef LEVELS_H
#define LEVELS_H

typedef struct{
    char name[15];
    int bricks;
    int destructibleBricks;
    struct MAP *next;

}MAP_t;

typedef struct{
    MAP_t *top;
}stack_t;


MAP_t *loadLevel();
stack_t *createStack();
void freeStack(stack_t *stack);
void push(MAP_t *map,stack_t *stack);
MAP_t *pop(stack_t *stack);

#endif
