#ifndef TIMER_H
#define TIMER_H

#define PAD_TIMER_RESET 5
#define BALL_TIMER_RESET 2
class Timer {
    private:
        short value;
        short resetValue;
        bool activated;

    public:
        void resetTimer();
        bool checkTimer();


        //GETTERS
        short getValue() const {return value;}
        short getResetValue() const {return resetValue;}
        bool getActivated() const {return activated;}

        //SETTERS
        void setValue(short newValue) { value = newValue;}
        void setResetValue(short newResetValue) { resetValue = newResetValue;}
        void setActivated(bool newActivated) {activated = newActivated;}
};
#endif
