#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <vector>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL.h>

typedef struct{
    SDL_Rect rect;
    int value;
}array_member;

typedef struct{
    int algorithim;
}Array;


int initializeArray(SDL_Window *window, std::vector<array_member> &vector);

int highlightValue(array_member value, SDL_Window *window);

int updateValueColumn(array_member &value, SDL_Window *window);
int clearValueColumn(array_member &value, SDL_Window *window);
#endif 
