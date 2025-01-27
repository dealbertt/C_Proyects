#include <stdio.h>
#include <stdlib.h>
#include "header/levels.h"

//Maybe i should create a struct map with all the necessary information
//and then i can create a list of maps with those structs
#define levelFile "levels.txt"
//its not going to be MAP_t but a stack with all the levels on the list
MAP_t  *loadLevel(){
    FILE *ptr = fopen(levelFile,"r");
    if(ptr == NULL){
        printf("Error while trying to open the file \n");
        return NULL;
    }

    MAP_t *map = malloc(sizeof(MAP_t));
    if(map == NULL){
        printf("Error while allocating memory for map\n");
        free(map);
        return NULL;
    }
    fscanf(ptr,"%s\n",map->name);
    fscanf(ptr,"%d\n",&map->bricks);
    printf("Map name: %s\n",map->name);
    printf("Total number of bricks: %d\n",map->bricks);
    return map;
}
