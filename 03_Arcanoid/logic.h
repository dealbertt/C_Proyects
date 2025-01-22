#ifndef LOGIC_H
#define LOGIC_H

#include <stdbool.h>

extern short PAD_TIMER;        // Declare PAD_TIMER as extern
extern short BALL_TIMER;       // Declare BALL_TIMER as extern
extern const short PAD_TIMER_RESET; // Declare reset value as extern

bool timer(short *timer);
void resetTimer(const short initialValue, short *actualValue);

#endif

