#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "header/graphics.h"
#include <stdbool.h>
#include "header/logic.h"
#include "keyboard.c"
#include "header/levels.h"



void initGame(SDL_Window **window, SDL_Surface **surface, PAD **pad, BALL **ball,List **list);
void gameLoop(SDL_Window *window,SDL_Surface *surface,PAD *pad, BALL *ball);
int main(){

    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;


    //Draw borders and place pad in the default place

    BALL *ball = NULL;
    PAD *pad = NULL;

    List *list = NULL;

    initGame(&window,&surface,&pad,&ball,&list);


    printf("Start\n");
    gameLoop(window,surface,pad,ball);

    free(ball->timer);
    free(pad->timer);
    free(ball);
    free(pad);
    return 0;


}

void initGame(SDL_Window **window, SDL_Surface **surface, PAD **pad, BALL **ball,List **list){
    //Windows and SDL surfaces
    SDL_Init(SDL_INIT_VIDEO);

    *window = SDL_CreateWindow("Arcanoid",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,1000,0);
    if(*window == NULL){
        printf("Error creating SDL_Window\n");
        return;
    }
    *surface = SDL_GetWindowSurface(*window);
    if(*surface == NULL){
        printf("Error creating SDL_Surface\n");
        return;
    }

    //-------------------------
    
    //PAD INITIALIZATION
    
    *pad = malloc(sizeof(PAD));
    if(*pad == NULL){
        printf("Error allocating memory for pad\n");
        return;
    }
    (*pad)->x = 450;
    (*pad)->y = 960;
    (*pad)->timer = malloc(sizeof(TIMER));
    if((*pad)->timer == NULL){
        printf("Error allocating memory for pad timer\n");
        free(pad);
        return;
    }
    (*pad)->timer->value = PAD_TIMER_RESET;
    (*pad)->timer->resetValue = PAD_TIMER_RESET;
    (*pad)->timer->activated = false;

    //-------------------------

    //BALL INITIALIZATION
    
    drawPad(*window,*surface,(*pad)->x,(*pad)->y);
    *ball = malloc(sizeof(BALL));
    if(*ball == NULL){
        printf("Error allocating memory for ball\n");
        return;
    }
    (*ball)->timer = malloc(sizeof(TIMER));
    if((*ball)->timer == NULL){
        printf("Error allocating memory for ball timer\n");
        free(ball);
        return;
    }
    
    (*ball)->timer->value = BALL_TIMER_RESET;
    (*ball)->timer->resetValue = BALL_TIMER_RESET;
    (*ball)->timer->activated = false;
    (*ball)->x = 500;
    (*ball)->y = 940;
    (*ball)->deltaX = 0;
    (*ball)->deltaY = 1;
    drawBall((*ball)->x, (*ball)->y, *window, *surface, WHITE, true);

    //----------------------------

    //Level List and borders
    *list = createList();

    printf("Name of head: %s\n",(*list)->head->name);
    printf("Name of middle: %s\n",(*list)->head->next->name);
    printf("Name of tail: %s\n",(*list)->tail->name);

    loadLevel((*list)->head,*surface);

    drawBorders(*window, *surface);

    //-------------------------

    printf("Game initialized correctly\n");

    return;

}   



void gameLoop(SDL_Window *window,SDL_Surface *surface,PAD *pad, BALL *ball){
   

    printf("Press Space to continue\n");
    while(!pressToContinue()){

    }
    
    while(!handleKeyboard(window, surface, pad)){
        clearBall(ball->x, ball->y, window, surface);
        updateBall(ball);
        drawBall(ball->x, ball->y, window, surface, WHITE, true);
    }
    return;
 
}

