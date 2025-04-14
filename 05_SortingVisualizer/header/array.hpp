#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <vector>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL.h>

typedef struct{
    SDL_FRect rect;
    int value;
}array_member;

typedef struct{
    int algorithim;
}Array;


int initializeArray(SDL_Window *window, SDL_Renderer *renderer, std::vector<array_member> &vector);

int highlightValue(SDL_Window *window, SDL_Renderer *renderer, array_member value);

int updateValueColumn(SDL_Window *window, SDL_Renderer *renderer, array_member &value);
int clearValueColumn(SDL_Window *window, SDL_Renderer *renderer, array_member &value);

int showSortedArray(std::vector<array_member> &vector, SDL_Window *window);
#endif 
