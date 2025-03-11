#ifndef PAD_H
#define PAD_H
#include <iostream>
#include "timer.hpp"
#include "graphics.h"

#define PLAYER1_DEFAULT_X 20
#define PLAYER2_DEFAULT_X 1000
#define PAD_DEFAULT_Y 500

class Pad {
    private:
        int xPos;
        int yPos;
        int xCollisionCoord;
        //timer for movement
        Timer timer;


    public:
        Pad(int x, int y, int xCollisionCoord);
        void Initialize();
        void drawPad(SDL_Window *window, SDL_Surface *surface);
        void clearPad(SDL_Window *window, SDL_Surface *surface);
        void movePadUp(SDL_Window *window, SDL_Surface *surface);
        void movePadDown(SDL_Window *window, SDL_Surface *surface);
        

        //GETTERS
        int getXpos() const { return xPos; }
        int getYpos() const { return yPos; }
        int getXcollisionCoord() const { return xCollisionCoord; }

        //SETTERS
        void setXpos(int newXpos){ xPos = newXpos; }
        void setYpos(int newYpos){ yPos = newYpos; }
        void setXcollisionCoord(int newCollision){ xCollisionCoord = newCollision; }

        //BIT OF BOTH
        Timer &getTimer() { return timer;}
};

#endif 
