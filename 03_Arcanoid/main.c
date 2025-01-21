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


void initGame(SDL_Window **window, SDL_Surface **surface);
bool handleKeyboard(SDL_Window *window,SDL_Surface *surface,int *x, int *y,short *timer);
bool timer(short *timer);
void resetTimer(short *timer);
int main(){
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;


    //Draw borders and place pad in the default place
    initGame(&window,&surface);

    int x = 50;

    int y = 960;
    int i = 1;
    short timer = 5;
    while(!handleKeyboard(window,surface,&x,&y,&timer)){
        printf("Timer %d\n",timer);
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


bool handleKeyboard(SDL_Window *window,SDL_Surface *surface,int *x, int *y,short *time){
     bool quit = false;
     SDL_Event event;
     //SDL_WaitEvent(&event);
     SDL_PollEvent(&event);
     if(timer(time)){

         if(event.type == SDL_KEYDOWN){
             if(event.key.keysym.sym == SDLK_ESCAPE){
                 quit = true;
                 return quit;
             }else if(event.key.keysym.sym == SDLK_d){
                 clearPad(window, surface, *x, *y);
                 *x += 50;
                 drawPad(window,surface,*x,*y);

             }else if(event.key.keysym.sym == SDLK_a){
                 clearPad(window, surface, *x, *y);
                 *x -= 50;
                 drawPad(window,surface,*x,*y);
             }

             resetTimer(time);
         }
     }

     return quit;
}
bool timer(short *timer){
    if(*timer <= 0){
        printf("TRUE\n");
        return true;
    }else{
        (*timer)--;
        return false;
    }

}
void resetTimer(short *timer){
    *timer = 5;
    return;
}
