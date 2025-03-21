#include "header/levels.h"
#include "header/graphics.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <string.h>

//Maybe i should create a struct map with all the necessary information
//and then i can create a list of maps with those structs
#define levelFile "levels/levels"
//its not going to be MAP_t but a stack with all the levels on the list


int levelList(MAP_t **head){
    *head = malloc(sizeof(MAP_t));
    if(head == NULL){
        printf("Error allocating memory for level\n");
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
    list->head = NULL;
    list->tail= NULL;
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

    fscanf(ptr,"%d\n",&size);

    char name[15];
    while(fscanf(ptr,"%s\n",name) != EOF){
        addToList(list, name);
    }
    fclose(ptr);
    return list;
}
void addToList(List *list,char levelName[15]){
    MAP_t *level = malloc(sizeof(MAP_t));
    strcpy(level->name,levelName);
    if(list->head == NULL){
        list->head = level;
        list->tail = level;

    }else{
        list->tail->next = level;
        list->tail = level;
    }
    level->completed = false;
    level->completed = false;
    list->size++;
    return;

}

int loadLevel(MAP_t *level, SDL_Surface *surface){
    char path[30] = "levels/";
    char *root = strcat(path,level->name);
    printf("Total name: %s\n",root);
    FILE *ptr = fopen(root ,"r");
    if(ptr == NULL){
        printf("Error while trying to open the file\n");
        return 1;
    }
    int rows;
    fscanf(ptr,"%d %d\n",&level->bricks,&rows);
    printf("Number of bricks: %d\n",level->bricks);
    int y = 0;int n = 0;int x = 175;
    int color = 0;
    for(int i = 0; i < rows; i++){
        x = 340;
        fscanf(ptr,"%d %d",&y,&n);
        for(int i = 0; i < n; i++){
            fscanf(ptr,"%d ",&color);
            drawBrick(x, y, surface, selectColor(color));
            
            x += BRICK_WIDTH; 
        }
        fscanf(ptr,"\n");
    }


    return 0;

}
uint32_t selectColor(int n){
    uint32_t color;
    switch (n) {
        case 0:
            //BLACK
            color = 0x00000000;
            break;
        case 1:
            //BLUE
            color = 0xFF0000FF;
            break;
        case 2:
            //RED
            color = 0xFFFF0000;
            break;
        case 3:
            //PURPLE
            color = 0xFFFF00FF;
            break;
        case 4:
            //GREEN
            color = 0xFF00FF00;
            break;
        case 5:
            //TURQUOISE
            color = 0xFF40E0D0;
            break;
        case 6:
            //YELLOW
            color = 0xFFFFFF00;
            break;
        case 7:
            //WHITE
            color = 0xFFFFFFFF;
            break;
        default:
            color = 0x00000000;
            break;

    }
    return color;

}
MAP_t *pop(List *list){
    if(list->head == NULL) return NULL;
    MAP_t *level = list->head;
    list->head = list->head->next;
    level->next = NULL;
    return level;
}

int resetObjects(PAD *pad, BALL *ball, List *list, SDL_Surface *surface, SDL_Window *window){
    //changing levels and updating list
    MAP_t *blank = malloc(sizeof(MAP_t));
    strcpy(blank->name,"blank");
    blank->completed = false;

    loadLevel(blank, surface);
    pop(list);
    loadLevel(list->head, surface);

    //-------------------------
    
    //Clearing both pad and ball to avoid having graphical glitches when resetting their position
    
    clearBall(ball->x, ball->y, window, surface);
    clearPad(window, surface, pad->x, pad->y);

    //Resetting everything that has to do with the pad
    pad->x = PAD_X;
    pad->y = PAD_Y;
    drawPad(window,surface,pad->x,pad->y);
    pad->timer->value = PAD_TIMER_RESET;
    pad->timer->resetValue = PAD_TIMER_RESET;
    pad->timer->activated = false;
    pad->leftSide = pad->x;
    pad->center = pad->x + 33;
    pad->rightside = pad->x + 66;

    //-------------------------

    //Resetting everything that has to do with the ball
    ball->timer->value = BALL_TIMER_RESET;
    ball->timer->resetValue = BALL_TIMER_RESET;
    ball->timer->activated = false;
    ball->x = 470;
    ball->y = PAD_Y - BRICK_HEIGHT - 10;
    ball->coordX = ball->x + 10;
    ball->coordY = ball->y + 10;

    ball->deltaX = 0;
    ball->deltaY = 1;
    drawBall(ball->x, ball->y, window, surface, WHITE, true);

    //-------------------------

    printf("Press Space to continue\n");
    while(!pressToContinue()){
    }

    printf("Objects have been reset correctly\n");
    return 0;
}

