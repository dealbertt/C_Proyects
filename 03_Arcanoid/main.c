#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "graphics.h"

//lets ignore that ok?
void initGame();
int main(){

    initGame();
    return 0;


}

void initGame(){

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Arcanoid",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,1000,0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_Rect rect = {0,0,1000,1000};
    SDL_FillRect(surface, &rect, 0x00000000);
    SDL_UpdateWindowSurface(window);

    drawPad(window, surface);

    SDL_Delay(5000);

}   