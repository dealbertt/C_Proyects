#ifndef BALL_HPP
#define BALL_HPP

#include <SDL2/SDL.h>
#include <unistd.h>
#include <random>
#include "timer.hpp"
#include "pad.hpp"
#include "graphics.h"



#define BALL_DEFAULT_X 500
#define BALL_DEFAULT_Y 500

class Ball {
    private:
        int xPos;
        int yPos;
        int deltaX;
        int deltaY;
        //include timer for movement
        Timer timer;

    public: 
        Ball(int xPos, int yPos, int deltaX, int deltaY);
        void Initialize();
        void drawBall(SDL_Window *window,SDL_Surface *surface,Uint32 color, bool update);
        void clearBall(SDL_Window *window,SDL_Surface *surface);
        void updateBall(SDL_Window *window, SDL_Surface *surface);
        int chooseDelta();
        int invertDeltaX();
        int invertDeltaY();
        int collisionWithPlayers(Pad *player1, Pad *player2); 
        int collisionWithBorders();

        //GETTERS
        int getX() const { return xPos; }
        int getY() const { return yPos; }
        int getDeltaX() const { return deltaX; }
        int getDeltaY() const { return deltaY; }
        Timer getTimer() const { return timer;}
        
        //SETTERS
        void setX(int newX) { xPos = newX; }
        void setY(int newY) { yPos = newY; }
        void setDeltaX(int newDeltaX) { deltaX = newDeltaX; }
        void setDeltaY(int newDeltaY) { deltaY = newDeltaY; }

        Timer &getTimer() { return timer;}


};


#endif

