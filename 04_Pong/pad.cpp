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
    drawLine(xPos,yPos,window,surface,color);
    return;
}

void Pad::detectCollisions(Ball *ball){
    //idk, check if the pos x of ball and pad are the same
    if(ball->xPos == xPos + xCollisionCoord && ball->yPos <= yPos && ball->yPos >= (yPos * 5)){
    // i guess i can define the pad zones here
    }
}
