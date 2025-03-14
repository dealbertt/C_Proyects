#include <iostream>
#include <ostream>
#include "header/ball.hpp"
#include "header/graphics.h"

Ball::Ball(float x, float y, float deltaX, float deltaY, float speed) : x(x), y(y), deltaX(deltaX), deltaY(deltaY), speed(speed){}


void Ball::Initialize(){
    std::cout << " Ball X position: " << x<< " Ball Y position: " << y<< std::endl;
    std::cout << " Ball X delta: " << deltaX << " Ball Y delta: " << deltaY << std::endl;
    return;
}


void Ball::drawBall(SDL_Window *window,SDL_Surface *surface,Uint32 color, bool update){
    drawBrick(x, y, surface, color);
    if(update){SDL_UpdateWindowSurface(window);}
    return;
}

void Ball::clearBall(SDL_Window *window,SDL_Surface *surface){
    drawBall(window, surface, BLACK, false);
    return;
}

void Ball::updateBall(SDL_Window *window, SDL_Surface *surface, float deltaTime){
    clearBall(window, surface);
    if (y <= 0 || y >= 600 - BRICK_HEIGHT) { deltaY *= -1; } // Bounce off top/bottom
    x += speed * deltaX * deltaTime;
    y += speed * deltaY * deltaTime;
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

int Ball::invertDeltaX(){
    if(getDeltaX() > 0){
        setDeltaX(-1);
    }else{
        setDeltaX(1);
    }
    return 0;
}

int Ball::invertDeltaY(){
    if(getDeltaY() > 0){
        setDeltaY(-1);
    }else{
        setDeltaY(1);
    }
    return 0;
}


int Ball::collisionWithPlayers(Pad *player1, Pad *player2){
    if(getDeltaX() > 0){
        //moving to the right 
        if((getX() + BRICK_WIDTH == player2->getXpos() + player2->getXcollisionCoord()) && (getY() >= player2->getYpos() && getY() <= (player2->getYpos() + 100))){
            std::cout << "Collision with Player2!" << std::endl;
            invertDeltaX();
            choosePadZone(player2);
            //function that choose the pad zone
            return 2;
        }
    }else if(getDeltaX() < 0){
        //moving to the left
        if((getX() == player1->getXpos() + player1->getXcollisionCoord()) && (getY() >= player1->getYpos() && getY() <= (player1->getYpos() + 100))){
            std::cout << "Collision with Player1!" << std::endl;
            invertDeltaX();
            choosePadZone(player1);
            //function that choose the pad zone
            return 1;
        }
    }
    return 0;
}

int Ball::collisionWithBorders(){
    if(getY() == 20){
        invertDeltaY();
        return 0;
    }else if(getY() == WINDOW_HEIGHT - 40){
        invertDeltaY();
        return 0;
    }
    return 1;
}

int Ball::choosePadZone(Pad *player){
    int zone = 0;
    int padY = player->getYpos();
    if(getY() >= padY && getY() < padY + 40){setDeltaY(1);}
    if(getY() >= padY + 40 && getY() < padY + 60){return 0;}
    if(getY() >= padY + 60 && getY() < padY + 100){setDeltaY(-1);}
    return zone;
}
