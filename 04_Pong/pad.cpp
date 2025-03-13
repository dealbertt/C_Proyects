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
        yPos -= 10;
        drawPad(window, surface, color);
        return 0;
    }
    return 1;
}

int Pad::movePadDown(SDL_Window *window, SDL_Surface *surface){
    if(timer.checkTimer() && getYpos() < WINDOW_HEIGHT - 120){
        clearPad(window, surface);
        yPos += 10;
        drawPad(window, surface, color);
        return 0;
    }
    return 1;
}

int Pad::playerMoves(int values[4]){
    std::cout << "Ball delta X: " << values[0] << std::endl;
    std::cout << "Ball delta Y: " << values[1] << std::endl;
    
    std::cout << "Ball position X: " << values[2] << std::endl;
    std::cout << "Ball position Y: " << values[3] << std::endl;

    return 0;
}
