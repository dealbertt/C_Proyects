#include "logic.h"
#include <stdio.h>
#include <stdbool.h>

short BALL_TIMER = 500;
const short PAD_TIMER_RESET = 2;
//i have an idea
bool timer(short *timer){

        if(*timer <= 0){
            printf("TRUE\n");
            return true;
        }else{
            *timer = *timer - 1;
            return false;
        }

}
void resetTimer(const short initialValue,short *actualValue){
    *actualValue = initialValue;
    return;
}

bool timer2(TIMER *timer){
    printf("TIME %hi\n",timer->value);
    if(timer->value <= 0){
        timer->activated = true;
        timer->value = timer->resetValue;
        return true;
    }else{
        timer->value --;
    }

    return false;
}

