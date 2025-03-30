#ifndef PAD_H
#define PAD_H
#include "graphics.h"

#define PLAYER1_DEFAULT_X 20.0f
#define PLAYER2_DEFAULT_X (WINDOW_WIDTH - 40.0f) 
#define PAD_DEFAULT_Y WINDOW_HEIGHT / 2.0f 


class Pad {
    protected:
        float x;
        float y;
        float previousY;
        float speed;
        float xCollisionCoord;
        Uint32 color;
        //timer for movement


    public:
         virtual ~Pad() = default;
         Pad(float x, float y, float speed, float xCollisionCoord, Uint32 color) 
        : x(x), y(y), speed(speed), xCollisionCoord(xCollisionCoord), color(color) {}
         virtual void Initialize() = 0;
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
        Uint32 getColor() const { return color; }

        //SETTERS
        void setXpos(float newXpos){ x= newXpos; }
        void setYpos(float newYpos){ y= newYpos; }
        void setPreviousY(float oldYpos){ previousY = oldYpos; }
        void setSpeed(float newSpeed){ speed = newSpeed; }
        void setXcollisionCoord(int newCollision){ xCollisionCoord = newCollision; }

        virtual int playerMoves(float yPos, SDL_Window *window, SDL_Surface *surface, float deltaTime) = 0; //Virtual method 
};

class Bot : public Pad{
        int randomPadPosition;

    public:
        Bot(float x, float y, float speed, float xCollisionCoord, Uint32 color) 
            : Pad(x, y, speed, xCollisionCoord, color), randomPadPosition(0) {}
        
        int getRandomPadPosition() const { return randomPadPosition; }
        void setRandomPadPosition(int newPad){randomPadPosition = newPad; }
        int assignRandomPadPosition();

        int playerMoves(float yPos, SDL_Window *window, SDL_Surface *surface, float deltaTime) override; //Virtual method 
        void Initialize() override;
};

class Player : public Pad{
    protected:
        int typePlayer;
    public:
    //i guess keyboard or input functions to move the pad and stuff
        Player(float x, float y, float speed, float xCollisionCoord, Uint32 color)
            : Pad(x, y, speed, xCollisionCoord, color) {} 

        void Initialize() override;
        int playerMoves(float yPos, SDL_Window *window, SDL_Surface *surface, float deltaTime) override; //Virtual method 
                                                                                                         //
};
#endif 
