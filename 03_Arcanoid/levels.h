#ifndef LEVELS_H
#define LEVELS_H

typedef struct{
    char name[15];
    int bricks;
    int destructibleBricks;

}MAP;


MAP *loadLevel();

#endif
