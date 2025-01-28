#include "header/levels.h"

//Maybe i should create a struct map with all the necessary information
//and then i can create a list of maps with those structs
#define levelFile "levels/levels.txt"
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

int levelList(MAP_t **head){
    *head = malloc(sizeof(MAP_t));
    if(head == NULL){
        printf("Error allocating memory for level\n");
        return 1;
        return 1;
    }
    FILE *ptr = fopen(levelFile,"r");
    fscanf(ptr,"%s",(*head)->name);
    printf("first level name: %s\n",(*head)->name);
    fclose(ptr);
    return 0;
}

List *createList(){
    List *list = malloc(sizeof(List));
    if(list == NULL){
        printf("Error allocating memory for list\n");
        return NULL;
    }
    FILE *ptr = fopen(levelFile,"r");
    if(ptr == NULL){
        printf("Error while trying to open the file\n");
        return NULL;
    }
    int size = 0;
    MAP_t *head = malloc(sizeof(MAP_t));
    list->head = head;
    fscanf(ptr,"%d\n",&size);
    fscanf(ptr,"%s\n",head->name);
    
    return list;
}
void addToList(List *list,char levelName[15]){
    MAP_t *level = malloc(sizeof(MAP_t));
    strcpy(level->name,levelName);
    printf("Level name: %s\n",level->name);
    if(list->head == NULL){
        list->head = level;
        list->tail = level;
    }else{
        list->tail->next = level;
        list->tail = level;
    }
    list->size++;
    return;

}


