#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdbool.h>
#include "graphics.h"
#include <unistd.h>

#define CHECK_SIZE BRICK_WIDTH/4
typedef struct{
    bool bits[5];
    SDL_Rect checkers[5];
}LAYER;

int assingCheckers(LAYER *layer,BALL *ball,SDL_Surface *surface,SDL_Window *window);
bool checkCollisions(SDL_Surface *surface, BALL *ball, SDL_Window *window);
#endif
