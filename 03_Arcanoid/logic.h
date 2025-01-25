#ifndef LOGIC_H
#define LOGIC_H

#include <stdbool.h>

#define PAD_TIMER_RESET 5

typedef struct {
    short value;
    short resetValue;
    bool activated;
}TIMER;

void resetTimer(const short initialValue, short *actualValue);
bool timer2(TIMER *timer);
#endif

