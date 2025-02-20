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
    bool bits[5];
    SDL_Rect checkers[5];
}LAYER;

typedef struct{
    int x;
    int y;
    int deltaX;
    int deltaY;
    TIMER *timer;
    LAYER *layer;
}BALL;

typedef struct{
    int x;
    int y;
    TIMER *timer;
}PAD;


void resetTimer(const short initialValue, short *actualValue);
bool timer(TIMER *timer);

void updateBall(BALL *ball);
int negateDelta(int delta);
#endif

