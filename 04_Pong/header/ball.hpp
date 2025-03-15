#ifndef BALL_HPP
#define BALL_HPP

#include <SDL2/SDL.h>
#include <unistd.h>
#include <random>
#include "timer.hpp"
#include "pad.hpp"
#include "graphics.h"



#define BALL_DEFAULT_X WINDOW_WIDTH / 2.0f
#define BALL_DEFAULT_Y WINDOW_HEIGHT / 2.0f

class Ball {
    private:
        float x, y;
        float deltaX;
        float deltaY;
        float speed;
        //include timer for movement

    public: 
        Ball(float x, float y, float deltaX, float deltaY, float speed);
        void Initialize();
        void drawBall(SDL_Window *window,SDL_Surface *surface,Uint32 color, bool update);
        void clearBall(SDL_Window *window,SDL_Surface *surface);
        void updateBall(SDL_Window *window, SDL_Surface *surface, float deltaTime);
        int chooseDelta();
        int invertDeltaX();
        int invertDeltaY();
        int collisionWithPlayers(Pad *player1, Pad *player2); 
        int collisionWithBorders();
        int choosePadZone(Pad *player);

        //GETTERS
        float getX() const { return x; }
        float getY() const { return y; }
        float getDeltaX() const { return deltaX; }
        float getDeltaY() const { return deltaY; }
        
        //SETTERS
        void setX(float newX) { x= newX; }
        void setY(float newY) { y= newY; }
        void setDeltaX(float newDeltaX) { deltaX = newDeltaX; }
        void setDeltaY(float newDeltaY) { deltaY = newDeltaY; }


};


#endif

