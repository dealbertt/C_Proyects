#ifndef TIMER_H
#define TIMER_H

#define PAD_TIMER_RESET 5
#define BALL_TIMER_RESET 2
class Timer {
    public:
        short value;
        short resetValue;
        bool activated;

        void resetTimer();
        bool checkTimer();
};
#endif
