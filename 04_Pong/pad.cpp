#include <SDL2/SDL_surface.h>
#include <iostream>
#include "header/pad.hpp"
#include "header/graphics.h"

Pad::Pad(int x, int y, int xCollisionCoord) : xPos(x), yPos(y), xCollisionCoord(xCollisionCoord){}

void Pad::Initialize(){
    std::cout << " Pad X position: " << xPos << " Pad Y position: " << yPos << std::endl;
    return;
}

void Pad::drawPad(SDL_Window *window, SDL_Surface *surface){
    Uint32 color = 0xFFFF0000;
    drawColumn(xPos, yPos, window, surface, color);
    return;
}

void Pad::clearPad(SDL_Window *window, SDL_Surface *surface){
    Uint32 color = 0x00000000;
    drawColumn(xPos,yPos,window,surface,color);
    return;
}


void Pad::movePadUp(SDL_Window *window, SDL_Surface *surface){
    if(timer.checkTimer()){
        clearPad(window, surface);
        yPos -= 10;
        drawPad(window, surface);
    }
    return;
}

void Pad::movePadDown(SDL_Window *window, SDL_Surface *surface){
    if(timer.checkTimer()){
        clearPad(window, surface);
        yPos += 10;
        drawPad(window, surface);
    }
    return;
}

