#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL.h>
#include <stdint.h>
void drawPad(SDL_Window *window, SDL_Surface *surface);
void drawLine(int x,int y, SDL_Window *window, SDL_Surface *surface,Uint32 color);
void drawBrick(int x,int y,SDL_Surface *surface ,Uint32 color);
void drawColumn(int x,int y, SDL_Window *window, SDL_Surface *surface,Uint32 color);
void clearPad(SDL_Window *window, SDL_Surface *surface);
void drawBorders(SDL_Window *window, SDL_Surface *surface);
#endif // !GRAPHICS_H
