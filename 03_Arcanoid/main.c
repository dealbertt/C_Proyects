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
bool handleKeyboard(SDL_Window *window,SDL_Surface *surface,int *x, int *y);
int main(){
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;


    //Draw borders and place pad in the default place
    initGame(&window,&surface);

   

    int x = 50;

    int y = 960;
   
    while(!handleKeyboard(window,surface,&x,&y)){
   } 
    SDL_Quit();
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


bool handleKeyboard(SDL_Window *window,SDL_Surface *surface,int *x, int *y){
  if(timer(&PAD_TIMER)){
        printf("timer %hi \n",PAD_TIMER);

    }else{
        
        printf(" nop timer %hi \n",PAD_TIMER);
    }


    bool quit = false;
        SDL_Event event;
        //SDL_WaitEvent(&event);
        SDL_PollEvent(&event);

        if(event.type == SDL_KEYDOWN){
            if(event.key.keysym.sym == SDLK_ESCAPE){
                quit = true;
                return quit;
            }else if(event.key.keysym.sym == SDLK_d && *x < 880){
                clearPad(window, surface, *x, *y);
                *x += 50;
                drawPad(window,surface,*x,*y);

            }else if(event.key.keysym.sym == SDLK_a && *x > 50){
                clearPad(window, surface, *x, *y);
                *x -= 50;
                drawPad(window,surface,*x,*y);
            }

        
    }
     return quit;
}

