#ifndef TIMER_HPP
#define TIMER_HPP

typedef struct{
    int value;
    int resetValue;
    bool activated;
}TIMER;

bool checkTimer(TIMER *timer);
void resetTimer(TIMER *timer);


#endif
