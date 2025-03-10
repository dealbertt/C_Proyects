#ifndef BALL_HPP
#define BALL_HPP

#include <SDL2/SDL.h>
#include <unistd.h>
#include <random>
#include "timer.hpp"
#include "graphics.h"



#define BALL_DEFAULT_X 500
#define BALL_DEFAULT_Y 500

class Ball {
    public: 
        int xPos;
        int yPos;
        int deltaX;
        int deltaY;
        //include timer for movement
        Timer timer;

        Ball(int xPos, int yPos, int deltaX, int deltaY);
        void Initialize();
        void drawBall(SDL_Window *window,SDL_Surface *surface,Uint32 color, bool update);
        void clearBall(SDL_Window *window,SDL_Surface *surface);
        void updateBall(SDL_Window *window, SDL_Surface *surface);
        int chooseDelta();
};

#endif

