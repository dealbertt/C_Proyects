#ifndef PAD_H
#define PAD_H
#include <SDL2/SDL_stdinc.h>
#include <iostream>
#include "graphics.h"

#define PLAYER1_DEFAULT_X 20.0f
#define PLAYER2_DEFAULT_X (WINDOW_WIDTH - 40.0f) 
#define PAD_DEFAULT_Y WINDOW_HEIGHT / 2.0f 


class Pad {
    private:
        float x;
        float y;
        float previousY;
        float speed;
        float xCollisionCoord;
        int randomPadPosition;
        Uint32 color;
        //timer for movement


    public:
        Pad(float x, float y, float speed, float xCollisionCoord, Uint32 color);
        void Initialize();
        void drawPad(SDL_Window *window, SDL_Surface *surface, Uint32 color);
        void clearPad(SDL_Window *window, SDL_Surface *surface);
        int movePadUp(SDL_Window *window, SDL_Surface *surface, float deltaTime);
        int movePadDown(SDL_Window *window, SDL_Surface *surface, float deltaTime);
        

        //GETTERS
        float getXpos() const { return x; }
        float getYpos() const { return y; }
        float getPreviousY() const { return previousY; }
        float getSpeed() const { return speed; }
        int getXcollisionCoord() const { return xCollisionCoord; }
        int getRandomPadPosition() const { return randomPadPosition; }
        Uint32 getColor() const { return color; }

        //SETTERS
        void setXpos(float newXpos){ x= newXpos; }
        void setYpos(float newYpos){ y= newYpos; }
        void setPreviousY(float oldYpos){ previousY = oldYpos; }
        void setSpeed(float newSpeed){ speed = newSpeed; }
        void setXcollisionCoord(int newCollision){ xCollisionCoord = newCollision; }
        void setRandomPadPosition(int newPad){randomPadPosition = newPad; }

        //BIT OF BOTH

        //PLAYER BEHAVIOUR
        int playerMoves(float yPos, SDL_Window *window, SDL_Surface *surface, float deltaTime);
        int assignRandomPadPosition();
        int PadHasTime();
};

#endif 
