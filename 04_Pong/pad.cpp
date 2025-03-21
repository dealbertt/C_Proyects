#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <iostream>
#include <random>
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
        previousY = y;
        clearPad(window, surface);
        y += speed * deltaTime;
        drawPad(window, surface, color);
    }
    return 1;
}

int Pad::playerMoves(float yPos, SDL_Window *window, SDL_Surface *surface, float deltaTime){
    //given that the speed of that pad and the ball are the same, it should alwauys be able to get there
    int Pos = getRandomPadPosition();
    if(yPos > getYpos()){
        if(y + Pos < yPos){
            movePadDown(window, surface, deltaTime);
        }else if(y + Pos > yPos){
            movePadUp(window, surface, deltaTime);
        }
        //maybe the pad does not have enough time to actually change to the random position
        //in that case, just move and bounce as it is
        //but if it does  have time, then assign the random value
    }else if(yPos < getYpos()){
        if(y + Pos < yPos){
            movePadDown(window, surface, deltaTime);
        }else if(y + Pos > yPos){
            movePadUp(window, surface, deltaTime);
        }
    }
    return 0;
}

int Pad::assignRandomPadPosition(){
    std::random_device seed;
    std::mt19937 gen{seed()};
    std::uniform_int_distribution<> dist{1,100};
    int guess = dist(gen);
    return guess;
}

