#ifndef LOGIC_H
#define LOGIC_H

#include <stdbool.h>

#define PAD_TIMER_RESET 5
#define BALL_TIMER_RESET 5

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
bool timer2(TIMER *timer);
#endif

