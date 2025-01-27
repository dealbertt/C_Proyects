#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL.h>
#include <stdint.h>
#include "logic.h"
void drawPad(SDL_Window *window, SDL_Surface *surface,int x,int y);
void drawLine(int x,int y, SDL_Window *window, SDL_Surface *surface,Uint32 color);
void drawBrick(int x,int y,SDL_Surface *surface ,Uint32 color);
void drawColumn(int x,int y, SDL_Window *window, SDL_Surface *surface,Uint32 color);
void clearPad(SDL_Window *window, SDL_Surface *surface,int x,int y);
void drawBorders(SDL_Window *window, SDL_Surface *surface);
void drawBall(int x, int y,SDL_Window *window,SDL_Surface *surface,Uint32 color);
void clearBall(int x, int y,SDL_Window *window,SDL_Surface *surface);
void simulateBall(SDL_Window *window,SDL_Surface *surface,TIMER *timer);
#endif // !GRAPHICS_H
