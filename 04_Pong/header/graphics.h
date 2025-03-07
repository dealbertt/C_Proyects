#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdbool.h>


#ifdef __cplusplus
extern "C" {
#endif 
    
#define BRICK_WIDTH 20
#define BRICK_HEIGHT  20
#define WINDOW_HEIGHT  1040
#define WINDOW_WIDTH 1040
#define PAD_RESET WINDOW_WIDTH/2
#define PAD_Y WINDOW_HEIGHT - BRICK_HEIGHT * 2
#define PAD_X 470


//COLORS
#define BLACK 0x00000000
#define BLUE 0xFF0000FF
#define RED 0xFFFF0000
#define PURPLE 0xFFFF00FF
#define GREEN 0xFF00FF000
#define TURQUOISE 0xFF40E0D0
#define YELLOW 0xFFFFFF00
#define WHITE 0xffffffff


void drawLine(int x,int y, SDL_Window *window, SDL_Surface *surface, Uint32 color, bool update);
void drawBrick(int x,int y,SDL_Surface *surface ,Uint32 color);
void drawColumn(int x,int y, SDL_Window *window, SDL_Surface *surface,Uint32 color, bool update);


void drawBorders(SDL_Window *window, SDL_Surface *surface, Uint32 color);

void drawBall(int x, int y,SDL_Window *window,SDL_Surface *surface,Uint32 color, bool update);
void clearBall(int x, int y,SDL_Window *window,SDL_Surface *surface);

#ifdef __cplusplus
}
#endif

#endif // !GRAPHICS_H
