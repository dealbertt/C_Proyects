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


SDL_Window *window;
SDL_Surface *surface;
void initGame(SDL_Window *window, SDL_Surface *surface);
bool handleKeyboard(int x,int y);
int main(){

    //Draw borders and place pad in the default place
    initGame(window,surface);

    int i = 1;
    int x = 0;
    int y = 0;
    while(handleKeyboard(x,y) != true){
        clearPad(window, surface, x, y);
        handleKeyboard(x, y);
        printf("Outside handling\n");
        printf("X: %d Y: %d\n",x,y);
        drawPad(window,surface,x,y);
    } 
    SDL_Quit();
    return 0;


}

void initGame(SDL_Window *window, SDL_Surface *surface){

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Arcanoid",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,1000,0);
    surface = SDL_GetWindowSurface(window);
    //drawPad(window, surface);
    drawPad(window,surface,500,960);
    drawBorders(window, surface);
    return;

}   


bool handleKeyboard(int x, int y){
    printf("Inside handling\n");
     bool quit = false;
     SDL_Event event = event;
     SDL_WaitEvent(&event);
     event.type = SDL_KEYDOWN;
                 switch (event.key.keysym.sym) {
                     case SDLK_ESCAPE:
                         quit = true;
                         return quit;
                    case SDLK_d:
                         //move pad right

                         clearPad(window, surface, 500, 960);
                         x = x + 50;
                         printf("D Key pressed\n");
                         return quit;
                    case SDLK_a:
                         //move pad left
                         x = x - 50;
                         return quit;
                 }
         
     return quit;
}
