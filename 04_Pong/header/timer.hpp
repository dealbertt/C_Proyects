#ifndef TIMER_HPP
#define TIMER_HPP

typedef struct{
    short value;
    short resetValue;
    bool activated;
}TIMER;

bool checkTimer(TIMER *timer);


#endif
