#include <SDL2/SDL_events.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "graphics.h"
#include <unistd.h>
#include <stdbool.h>


//lets ignore that ok?
void initGame();
void handleKeyboard();
int main(){

    initGame();
    
    handleKeyboard();
   
    SDL_Quit();
    return 0;


}

void initGame(){

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Arcanoid",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,1000,0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_Rect rect = {0,0,1000,1000};
    SDL_FillRect(surface, &rect, 0x00000000);
    SDL_UpdateWindowSurface(window);

    //drawPad(window, surface);
    Uint32 color = 0xffffffff;
    drawColumn(500, 800 ,window,surface,color);
    drawLine(500, 800,window,surface,color);
    drawPad(window,surface);
    drawBorders(window, surface);
    simulateBall (window, surface);
    return;

}   


void handleKeyboard(){
     bool quit = false;
     SDL_Event event;

     while(!quit){
         SDL_WaitEvent(&event);
         switch (event.type) {
             case SDL_KEYDOWN:
                 switch (event.key.keysym.sym) {
                     case SDLK_ESCAPE:
                         quit = true;
                         break;
                 }
                break;
         }
     }
     return;
}
