#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdbool.h>
#include "graphics.h"
#include <unistd.h>

#define CHECK_SIZE BRICK_WIDTH/5

int assingCheckers(BALL *ball,SDL_Window *window, PAD *pad);
bool checkCollisions(BALL *ball, SDL_Window *window, PAD *pad);
int getColorData(SDL_Window *window, BALL *ball, int startX, int startY,int width,int index);
void changeDelta(BALL *ball);
void changeDeltaWithPad(BALL *ball, PAD *pad);
#endif
