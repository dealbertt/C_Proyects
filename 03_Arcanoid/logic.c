#include <stdio.h>
#include <stdbool.h>
short PAD_TIMER = 50;
short BALL_TIMER = 50;
const short PAD_TIMER_RESET = 50;
bool timer(short *timer){
        printf("timer %hi\n",PAD_TIMER);
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


