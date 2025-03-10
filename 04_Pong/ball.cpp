#include <iostream>
#include <ostream>
#include "header/ball.hpp"
#include "header/graphics.h"

Ball::Ball(int xPos, int yPos, int deltaX, int deltaY) : xPos(xPos), yPos(yPos), deltaX(deltaX), deltaY(deltaY){}


void Ball::Initialize(){
    std::cout << " Ball X position: " << xPos << " Ball Y position: " << yPos << std::endl;
    std::cout << " Ball X delta: " << deltaX << " Ball Y delta: " << deltaY << std::endl;
    return;
}


void Ball::drawBall(SDL_Window *window,SDL_Surface *surface,Uint32 color, bool update){
    drawBrick(xPos, yPos, surface, color);
    if(update){SDL_UpdateWindowSurface(window);}
    return;
}

void Ball::clearBall(SDL_Window *window,SDL_Surface *surface){
    drawBall(window, surface, BLACK, false);
    return;
}

void Ball::updateBall(SDL_Window *window, SDL_Surface *surface){
    clearBall(window, surface);
    if(timer.checkTimer()){
        if(deltaX > 0){
            xPos += 5;
        }else if(deltaX < 0){
            xPos -= 5;
        }

        if(deltaY > 0){
            yPos -= 5;
        }else if(deltaY < 0){
            yPos += 5;
        }
    }
    drawBall(window, surface, WHITE, false);
    return;
}

int Ball::chooseDelta(){
    std::random_device rd;  // Seed for the random number engine
    std::mt19937 gen(rd()); // Mersenne Twister PRNG
    std::uniform_int_distribution<int> dist(0, 1); // Generates 0 or 1

    int choice = (dist(gen) * 2) - 1; // Convert 0 to -1 and 1 to 1

    std::cout << "Random choice: " << choice << std::endl;
    return choice; 
}
