#include <iostream>
#include "header/ball.hpp"

Ball::Ball(int xPos, int yPos, int deltaX, int deltaY) : xPos(xPos), yPos(yPos), deltaX(deltaX), deltaY(deltaY){}


void Ball::Initialize(){
    std::cout << " Ball X position: " << xPos << " Ball Y position: " << yPos << std::endl;
    std::cout << " Ball X delta: " << deltaX << " Ball Y delta: " << deltaY << std::endl;
    return;
}

void Ball::moveBall(SDL_Window *window){


}

void Ball::drawBall(SDL_Window *window,SDL_Surface *surface,Uint32 color, bool update){
    /*
    SDL_Rect rect = {x,y,BRICK_WIDTH,BRICK_HEIGHT};
    SDL_FillRect(surface, &rect,color);
    */
    drawBrick(xPos, yPos, surface, color);
    if(update){SDL_UpdateWindowSurface(window);}
    return;
}

void Ball::clearBall(int x, int y,SDL_Window *window,SDL_Surface *surface){
    //drawBall(x,y,window,surface,0x00000000,false);
    drawBall(window, surface, BLACK, false);
    return;
}


