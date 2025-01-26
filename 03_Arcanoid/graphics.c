#include "graphics.h"
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>

#define BRICK_WIDTH 20
#define BRICK_HEIGHT  20
#define WINDOW_HEIGHT  1000
#define WINDOW_WIDTH 1000
#define PAD_RESET WINDOW_WIDTH/2
#define PAD_Y WINDOW_HEIGHT - BRICK_HEIGHT *2
#define PAD_X 500 

//Draw pad is going to be draw brick at the pad positions :)


//Clear ball is drawBall with black color
void drawBall(int x, int y,SDL_Window *window,SDL_Surface *surface,Uint32 color){
    SDL_Rect rect = {x,y,BRICK_WIDTH,BRICK_HEIGHT};
    SDL_FillRect(surface,&rect, color);
    SDL_UpdateWindowSurface(window);

    return;
}

void clearBall(int x, int y,SDL_Window *window,SDL_Surface *surface){
    drawBall(x,y,window,surface,0x00000000);
    return;
}

void simulateBall(SDL_Window *window,SDL_Surface *surface,TIMER *timer){
    if(timer2(timer)){
        int x = 500, y = 500;
        for(int i = 0; i < 20; i ++){
            drawBall(x, y, window, surface, 0xffffffff);;
            SDL_Delay(75);
            drawBall(x, y, window, surface, 0x00000000);
            y = y + BRICK_HEIGHT;
        }
    }
    return;
}
void drawPad(SDL_Window *window, SDL_Surface *surface,int x,int y){
    Uint32 color = 0xFFFF0000;
    drawLine(x,y,window,surface,color);
    return;
}


void clearPad(SDL_Window *window, SDL_Surface *surface,int x, int y){
    Uint32 color = 0x00000000;
    drawLine(x,y,window,surface,color);
    return;
}

void drawBrick(int x,int y,SDL_Surface *surface ,Uint32 color){

        SDL_Rect rect = {x,y,BRICK_WIDTH,BRICK_HEIGHT};
        SDL_FillRect(surface, &rect,color);

    return;
}

void drawLine(int x,int y, SDL_Window *window, SDL_Surface *surface, Uint32 color){
    for(int i = 0; i < 5; i ++){

        drawBrick(x,y,surface,color);
        x =  x + BRICK_WIDTH;


    }

    SDL_UpdateWindowSurface(window);
    return;
}

void drawColumn(int x,int y, SDL_Window *window, SDL_Surface *surface,Uint32 color){
    for(int i = 0; i < 5; i ++){

        drawBrick(x,y,surface,color);
        y =  y + BRICK_HEIGHT;


    }

    SDL_UpdateWindowSurface(window);
    return;
}

void drawBorders(SDL_Window *window, SDL_Surface *surface){
    Uint32 color = 0xFF0000FF;
    int x = 0, y = 0;
    for(int i = 0; i < 10; i ++){
        drawColumn(x, y,window, surface, color);
        y = y + 100;
    }
    x = 980;
    y = 0;
    for(int i = 0; i < 10; i ++){
        drawColumn(x, y,window, surface, color);
        y = y + 100;
    }
    x = 0;
    y = 0;
    for(int i = 0; i < 10; i ++){
        drawLine(x, y,window, surface, color);
        x = x + 100;
    }
    x = 0;
    y = 980;
    for(int i = 0; i < 10; i ++){
        drawLine(x, y,window, surface, color);
        x = x + 100;
    }
    return;
}
