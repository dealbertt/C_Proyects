#ifndef TIMER_HPP
#define TIMER_HPP

typedef struct{
    unsigned short value;
    unsigned short resetValue;
    bool activated;
}TIMER;

bool checkTimer(TIMER *timer);
void resetTimer(TIMER *timer);


#endif
