#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "graphics.h"
#include <unistd.h>
#include <stdbool.h>
#include "logic.h"


void initGame(SDL_Window **window, SDL_Surface **surface);
bool handleKeyboard(SDL_Window *window,SDL_Surface *surface,int *x, int *y,TIMER *timer);
bool Exit();
void gameLoop(SDL_Window *window,SDL_Surface *surface,TIMER *timer);
int main(){
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;


    //Draw borders and place pad in the default place
    initGame(&window,&surface);

    TIMER *padTimer = malloc(sizeof(TIMER));
    padTimer->value = PAD_TIMER;
    padTimer->resetValue = PAD_TIMER_RESET;


    gameLoop(window,surface,padTimer);

    free(padTimer);
    return 0;


}

void initGame(SDL_Window **window, SDL_Surface **surface){
      SDL_Init(SDL_INIT_VIDEO);
    *window = SDL_CreateWindow("Arcanoid",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,1000,0);
    *surface = SDL_GetWindowSurface(*window);
    //drawPad(window, surface);
    drawBorders(*window, *surface);
    drawPad(*window,*surface,500,960);
    return;

}   


bool handleKeyboard(SDL_Window *window,SDL_Surface *surface,int *x, int *y,TIMER *timer){

    bool quit = false;
    if(timer2(timer)){

        printf("WORKS\n timer: %hi\n",timer->value);
        SDL_Event event;
        //SDL_WaitEvent(&event);
        SDL_PollEvent(&event);

        if(event.type == SDL_KEYDOWN){
            if(event.key.keysym.sym == SDLK_d && *x < 880){
                clearPad(window, surface, *x, *y);
                *x += 50;
                drawPad(window,surface,*x,*y);

            }else if(event.key.keysym.sym == SDLK_a && *x > 50){
                clearPad(window, surface, *x, *y);
                *x -= 50;
                drawPad(window,surface,*x,*y);
            }


        }
        
    }

     return quit;
}
bool Exit(){
    bool quit = false;
    SDL_Event event;
    SDL_PollEvent(&event);
    if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == SDLK_ESCAPE){
            SDL_Quit();
            printf("QUIT\n");
            return true;
        }
    }
    return quit;


}

void gameLoop(SDL_Window *window,SDL_Surface *surface,TIMER *timer){
    int x = 500;
    int y = 960;
    while(Exit() == false){
            handleKeyboard(window,surface,&x,&y,timer);
    }
    return;
 
}

