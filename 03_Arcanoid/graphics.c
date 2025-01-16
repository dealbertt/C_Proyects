#include "graphics.h"
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

#define PAD_WIDTH 150
#define PAD_HEIGHT  25
#define WINDOW_HEIGHT  1000
#define WINDOW_WIDTH 1000
#define PAD_RESET WINDOW_WIDTH/2



void drawPad(SDL_Window *window, SDL_Surface *surface){

    int w,h;
    SDL_GetWindowSize(window, &w, &h);
    SDL_Rect rect = {PAD_RESET - PAD_WIDTH , WINDOW_HEIGHT- PAD_HEIGHT,PAD_WIDTH,PAD_HEIGHT};
    SDL_FillRect(surface, &rect, 0xffffffff);
    SDL_UpdateWindowSurface(window);
    return;
}
