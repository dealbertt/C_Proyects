#include <iostream>
#include <ostream>
#include "../header/ball.hpp"
#include "../header/graphics.h"

Ball::Ball(float x, float y, float deltaX, float deltaY, float speed) : x(x), y(y), deltaX(deltaX), deltaY(deltaY), speed(speed){}


void Ball::Initialize(){
    std::cout << " Ball X position: " << x<< " Ball Y position: " << y<< std::endl;
    std::cout << " Ball X delta: " << deltaX << " Ball Y delta: " << deltaY << std::endl;
    return;
}


void Ball::drawBall(SDL_Window *window,SDL_Surface *surface,Uint32 color, bool update){
    drawBrick((int)x, (int)y, surface, color);
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
    y += speed * (deltaY * -1) * deltaTime;
    drawBall(window, surface, WHITE, false);
    return;
}

float Ball::chooseDelta(){
    std::random_device rd;  // Seed for the random number engine
    std::mt19937 gen(rd()); // Mersenne Twister PRNG
    std::uniform_int_distribution<int> dist(0, 1); // Generates 0 or 1

    float choice = (dist(gen) * 2) - 1; // Convert 0 to -1 and 1 to 1

    std::cout << "Random choice: " << choice << std::endl;
    return choice; 
}

void Ball::invertDeltaX(){
    if(getDeltaX() > 0){
        setDeltaX(-1.0f);
    }else{
        setDeltaX(1.0f);
    }
    return;
}

void Ball::invertDeltaY(){
    if(getDeltaY() > 0){
        setDeltaY(-1);
    }else{
        setDeltaY(1);
    }
    return;
}


int Ball::collisionWithPlayers(Pad *player1, Pad *player2, int mode){
    float baseMargin = 2.5f;
    float margin = baseMargin + (getSpeed() / 100.0f);
    Bot *bot1;
    Bot *bot2;
    if(mode == 1){
        bot2 = dynamic_cast<Bot *>(player2);
    }else if(mode == 3){
        bot2 = dynamic_cast<Bot *>(player2);
        bot1 = dynamic_cast<Bot *>(player1);
    }
    if(getDeltaX() > 0){
        //moving to the right 
        if ((getX() + BRICK_WIDTH >= player2->getXpos() - margin) && 
                (getY() >= player2->getYpos() && getY() <= (player2->getYpos() + 100))) {
            invertDeltaX();
            //function that choose the pad zone
            choosePadZone(player2);
            if(mode == 1 || mode == 3){
                int newPos = bot2->assignRandomPadPosition();
                bot2->setRandomPadPosition(newPos);
            }
            return 2;
        }
    }else if(getDeltaX() < 0){
        //moving to the left
        if ((getX() <= player1->getXpos() + player1->getXcollisionCoord() + margin) && 
                (getY() >= player1->getYpos() && getY() <= (player1->getYpos() + 100))) {
            invertDeltaX();
            //function that choose the pad zone
            choosePadZone(player1);
            if(mode == 3){
                int newPos = bot1->assignRandomPadPosition();
                bot1->setRandomPadPosition(newPos);
            }
            return 1;
        }
    }
    return 0;
}

int Ball::choosePadZone(Pad *player){
    int zone = 0;
    float state = player->getPreviousY() - getY();
    if(state > 0){
        //pad is going up
        /*
        if(getDeltaY() == -1.0f){
            //ball is going down
            setDeltaY(1.0f);
        }
        */
    }else if(state < 0){
        //pad is going down
        /*
        if(getDeltaY() == 1.0f){
            //ball is going up
            setDeltaY(-1.0f);
        }
        */
    }else{
        return 0;
    }
    return zone;
}

