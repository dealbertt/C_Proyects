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


