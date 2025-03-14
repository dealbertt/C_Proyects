#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <iostream>
#include "header/pad.hpp"
#include "header/graphics.h"

Pad::Pad(int x, int y, int xCollisionCoord, Uint32 color) : xPos(x), yPos(y), xCollisionCoord(xCollisionCoord), color(color){}

void Pad::Initialize(){
    std::cout << " Pad X position: " << xPos << " Pad Y position: " << yPos << std::endl;
    return;
}

void Pad::drawPad(SDL_Window *window, SDL_Surface *surface, Uint32 color){ 
    drawColumn(xPos, yPos, window, surface, color);
    return;
}

void Pad::clearPad(SDL_Window *window, SDL_Surface *surface){
    Uint32 color = 0x00000000;
    drawColumn(xPos,yPos,window,surface,color);
    return;
}


int Pad::movePadUp(SDL_Window *window, SDL_Surface *surface){
    if(timer.checkTimer() && getYpos() > 20){
        clearPad(window, surface);
        yPos -= 5;
        drawPad(window, surface, color);
        return 0;
    }
    return 1;
}

int Pad::movePadDown(SDL_Window *window, SDL_Surface *surface){
    if(timer.checkTimer() && getYpos() < WINDOW_HEIGHT - 120){
        clearPad(window, surface);
        yPos += 5;
        drawPad(window, surface, color);
        return 0;
    }
    return 1;
}

int Pad::playerMoves(int deltaY, SDL_Window *window, SDL_Surface *surface){
    //DELTA X: values 0 
    //DELTA Y: values 1 
    //BALL X: values 2
    //BALL Y: values 3
    if(deltaY > getYpos()){
        movePadDown(window, surface);
    }else if(deltaY < getYpos()){
        movePadUp(window, surface);
    }
    return 0;
}
