#include <iostream>
#include "header/pad.hpp"

Pad::Pad(int x, int y) : xPos(x), yPos(y){}

void Pad::Initialize(){
    std::cout << " Pad X position: " << xPos << " Pad Y position: " << yPos << std::endl;
    return;
}

void Pad::drawPad(SDL_Window *window, SDL_Surface *surface){
    Uint32 color = 0xFFFF0000;
    drawColumn(xPos, yPos, window, surface, color, false);
    return;
}

void Pad::clearPad(SDL_Window *window, SDL_Surface *surface){
    Uint32 color = 0x00000000;
    drawLine(xPos,yPos,window,surface,color,false);
    return;
}

void detectCollisions(Ball *ball){
    //idk, check if the pos x of ball and pad are the same
}
