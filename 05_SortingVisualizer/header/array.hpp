#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL.h>

typedef struct{
    SDL_Rect rect;
    int value;
}array_member;

int initializeArray(SDL_Window *window);

#endif 
