#ifndef BALL_HPP
#define BALL_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include "timer.hpp"
#include "graphics.h"

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
        void moveBall(SDL_Window *window);
        void drawBall(SDL_Window *window,SDL_Surface *surface,Uint32 color, bool update);
        void clearBall(int x, int y,SDL_Window *window,SDL_Surface *surface);
};

#endif

