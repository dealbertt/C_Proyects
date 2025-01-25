#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "graphics.h"
#include <stdbool.h>
#include "logic.h"


//sorry for no audio today, watching the 24 hourse of Daytona :)

void initGame(SDL_Window **window, SDL_Surface **surface);
bool handleKeyboard(SDL_Window *window,SDL_Surface *surface,int *x, int *y,TIMER *timer);
bool handleKeyboardSim(SDL_Window *window,SDL_Surface *surface,int *x, int *y,TIMER *timer);
bool Exit();
void gameLoop(SDL_Window *window,SDL_Surface *surface,TIMER *timer,TIMER *ballTimer);
int main(){
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;


    //Draw borders and place pad in the default place
    initGame(&window,&surface);

    TIMER *padTimer = malloc(sizeof(TIMER));
    padTimer->value = PAD_TIMER_RESET;
    padTimer->resetValue = PAD_TIMER_RESET;

    TIMER *ballTimer = malloc(sizeof(TIMER));
    ballTimer->value = PAD_TIMER_RESET;
    ballTimer->resetValue = PAD_TIMER_RESET;




    gameLoop(window,surface,padTimer,ballTimer);

    free(padTimer);
    free(ballTimer);
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

        //SDL_WaitEvent(&event);
        SDL_Event event;
        SDL_PollEvent(&event);

        if(event.type == SDL_KEYDOWN){

            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:

                    SDL_Quit();
                    printf("QUIT\n");
                    quit = true;

                    break;

                case SDLK_d:

                    if(*x < 875){
                        clearPad(window, surface, *x, *y);
                        *x += 25;
                        drawPad(window,surface,*x,*y);
                    }else{
                        drawPad(window, surface, *x, *y);
                    }

                    break;
                case SDLK_a:

                    if(*x > 25){
                        clearPad(window, surface, *x, *y);
                        *x -= 25;
                        drawPad(window,surface,*x,*y);
                    }else{
                        drawPad(window, surface, *x, *y);
                    }

                    break;
                default:
                    break;

            }
            system("clear");
            printf("X: %d Y: %d\n",*x,*y);
            printf("Timer: %d\n",timer->value);
        }

    }else{
        SDL_FlushEvent(SDL_KEYDOWN);
    }
    return quit;
}

void gameLoop(SDL_Window *window,SDL_Surface *surface,TIMER *timer,TIMER *ballTimer){
    int x = 500;
    int y = 960;
    while(!handleKeyboard(window, surface, &x, &y, timer)){
       
    }
    return;
 
}


bool handleKeyboardSim(SDL_Window *window,SDL_Surface *surface,int *x, int *y,TIMER *timer){

    bool quit = false;
    if(timer2(timer)){

        printf("WORKS\n timer: %hi\n",timer->value);
        //SDL_WaitEvent(&event);

        clearPad(window, surface, *x, *y);
        *x += 50;
        drawPad(window,surface,*x,*y);

    }

     return quit;
}


