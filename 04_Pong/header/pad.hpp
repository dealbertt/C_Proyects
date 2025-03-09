#ifndef PAD_H
#define PAD_H
#include <iostream>
#include "timer.hpp"
#include "ball.hpp"
#include "graphics.h"

#define PLAYER1_DEFAULT_X 20
#define PLAYER2_DEFAULT_X 1000
#define PAD_DEFAULT_Y 500

class Pad {
    public:
        int xPos;
        int yPos;
        int xCollisionCoord;
        //timer for movement
        Timer timer;


        Pad(int x, int y, int xCollisionCoord);
        void Initialize();
        void drawPad(SDL_Window *window, SDL_Surface *surface);
        void clearPad(SDL_Window *window, SDL_Surface *surface);
        void detectCollisions(Ball *ball);
};

#endif 
