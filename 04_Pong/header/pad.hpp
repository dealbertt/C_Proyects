#ifndef PAD_H
#define PAD_H
#include <SDL2/SDL_stdinc.h>
#include <iostream>
#include "timer.hpp"
#include "graphics.h"

#define PLAYER1_DEFAULT_X 20
#define PLAYER2_DEFAULT_X (WINDOW_WIDTH - 40) 
#define PAD_DEFAULT_Y WINDOW_HEIGHT / 2 


class Pad {
    private:
        int xPos;
        int yPos;
        int xCollisionCoord;
        Uint32 color;
        //timer for movement
        Timer timer;


    public:
        Pad(int x, int y, int xCollisionCoord, Uint32 color);
        void Initialize();
        void drawPad(SDL_Window *window, SDL_Surface *surface, Uint32 color);
        void clearPad(SDL_Window *window, SDL_Surface *surface);
        int movePadUp(SDL_Window *window, SDL_Surface *surface);
        int movePadDown(SDL_Window *window, SDL_Surface *surface);
        

        //GETTERS
        int getXpos() const { return xPos; }
        int getYpos() const { return yPos; }
        int getXcollisionCoord() const { return xCollisionCoord; }
        Uint32 getColor() const { return color; }

        //SETTERS
        void setXpos(int newXpos){ xPos = newXpos; }
        void setYpos(int newYpos){ yPos = newYpos; }
        void setXcollisionCoord(int newCollision){ xCollisionCoord = newCollision; }

        //BIT OF BOTH
        Timer &getTimer() { return timer;}

        //PLAYER BEHAVIOUR
        int playerMoves(int values[4]);
};

#endif 
