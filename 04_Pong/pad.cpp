#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <iostream>
#include "header/pad.hpp"
#include "header/graphics.h"

Pad::Pad(float x, float y, float speed, float xCollisionCoord, Uint32 color) : x(x), y(y), speed(speed), xCollisionCoord(xCollisionCoord), color(color){}

void Pad::Initialize(){
    std::cout << " Pad X position: " << x<< " Pad Y position: " << y<< std::endl;
    return;
}

void Pad::drawPad(SDL_Window *window, SDL_Surface *surface, Uint32 color){ 
    drawColumn((int)x, (int)y, window, surface, color);
    return;
}

void Pad::clearPad(SDL_Window *window, SDL_Surface *surface){
    Uint32 color = 0x00000000;
    drawColumn((int)x,(int)y,window,surface,color);
    return;
}


int Pad::movePadUp(SDL_Window *window, SDL_Surface *surface, float deltaTime){
    if(y >= 0){
        clearPad(window, surface);
        y -= speed * deltaTime;
        drawPad(window, surface, color);
    }
    return 1;
}

int Pad::movePadDown(SDL_Window *window, SDL_Surface *surface, float deltaTime){
    if(y <= WINDOW_HEIGHT - 100){
        clearPad(window, surface);
        y += speed * deltaTime;
        drawPad(window, surface, color);
    }
    return 1;
}

int Pad::playerMoves(float deltaY, SDL_Window *window, SDL_Surface *surface, float deltaTime){
    //DELTA X: values 0 
    //DELTA Y: values 1 
    //BALL X: values 2
    //BALL Y: values 3
    if(deltaY > getYpos()){
        movePadDown(window, surface, deltaTime);
    }else if(deltaY < getYpos()){
        movePadUp(window, surface, deltaTime);
    }
    return 0;
}
