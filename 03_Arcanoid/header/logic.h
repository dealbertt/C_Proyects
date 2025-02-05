#ifndef LOGIC_H
#define LOGIC_H

#include <stdbool.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include <unistd.h>

#define PAD_TIMER_RESET 5
#define BALL_TIMER_RESET 25

typedef struct {
    short value;
    short resetValue;
    bool activated;
}TIMER;

typedef struct{

    int x;
    int y;
    int deltaX;
    int deltaY;
    TIMER *timer;

}BALL;

typedef struct{

    int x;
    int y;
    TIMER *timer;

}PAD;



void resetTimer(const short initialValue, short *actualValue);
bool timer(TIMER *timer);
void checkBricks(BALL *ball, SDL_Surface *surface);
bool getBrickPixel(SDL_Surface *surface,int x,int y);
void updateBall(BALL *ball);
void getBallColision(BALL *ball,SDL_Surface *surface);
void CollisionStrucutureRight(bool bits[5], BALL *ball, SDL_Surface *surface);
void CollisionStrucutureLeft(bool bits[5], BALL *ball, SDL_Surface *surface);
#endif

